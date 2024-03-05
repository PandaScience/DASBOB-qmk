#!/bin/bash
KEYMAP_C="${PWD}/keymaps/default/keymap.c"
WORKDIR="${PWD}/keymap-drawer"
CONFIG="${WORKDIR}/config.yaml"
BASE="${WORKDIR}/base.yaml"
cd "${WORKDIR}" || ( echo "no such path: ${WORKDIR}" && exit 1 )

# HACK: work around missing include paths for e.g. "quantum.h" etc. to prevent:
# > The C pre-processor ran into a fatal error: <path>/features/custom_shift_keys.h:60:10: fatal error: quantum.h: No such file or directory
KEYMAP_TMP_C="$(dirname "${KEYMAP_C}")/keymap_tmp.c"
# comment offending include
sed '/custom_shift_keys.h/s/^/\/\/ /' "${KEYMAP_C}" > "${KEYMAP_TMP_C}"
KEYMAP_C="${KEYMAP_TMP_C}"

# dump default config if not present
if [ ! -f defaults.yaml ]; then
	keymap dump-config > defaults.yaml
fi

# merge default config with custom overrides
# NOTE: this requires "go-yq" v4.x, not the python implementation "yq"
yq '. *= load("overrides.yaml")' defaults.yaml > "${CONFIG}"
# parse yaml keymap from QMK code
LAYERS="$(awk -F"{|}" '/^enum layers/ {print $2}' "${KEYMAP_C}" | tr -d ',')"
# shellcheck disable=SC2086   # -> --layer-names requires word split
qmk c2json "${KEYMAP_C}" | \
	keymap --config "${CONFIG}" parse \
	--layer-names ${LAYERS} \
	--columns 10 \
	--qmk-keymap-json - \
	--base-keymap "${BASE}" \
	> keymap_.yaml
# HACK:
# manually append combos b/c they are currently not read from --base-keymap if
# no matching key positions are defined in the json (i.e. not working for QMK)
# https://github.com/caksoylar/keymap-drawer/blob/main/keymap_drawer/keymap.py#L173
yq '. *= load("combos.yaml")' keymap_.yaml > keymap.yaml

# draw svg with nice glyphs
keymap -c "${CONFIG}" draw -j ../info.json keymap.yaml > keymap.svg

# HACK: remove temp files
rm "${KEYMAP_TMP_C}" || true
rm keymap_.yaml || true
rm "${COFNIG}" || true
