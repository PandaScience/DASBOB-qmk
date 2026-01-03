#include QMK_KEYBOARD_H

#include "../../features/custom_shift_keys.h"
#include "../../macros.h"

#define ___x___ KC_NO
#define ___O___ KC_NO
#ifndef _______
#define _______ KC_TRNS
#endif

// generic layer tap-holds
#define sym(KC) LT(SYM, KC)
#define num(KC) LT(NUM, KC)
#define nav(KC) LT(NAV, KC)
#define mse(KC) LT(MSE, KC)
#define swp(KC) SH_T(KC)  // NOTE: breaks double-tap-repeat!

// home row mods left
#define HM_S sym(_S)
#define HM_T sl(_T)
#define HM_R gl(_R)
#define HM_D nav(_D)
#define HM_X cl(_X)
#define HM_K al(_K)

// home row mods right
#define HM_I sym(_I)
#define HM_A sr(_A)
#define HM_E gr(_E)
#define HM_N mse(_N)
#define HM_SL cr(_SLSH)
#define HM_DT al(_DOT)

// thumb key tap-holds
#define TH_X _X
#define TH_TAB ar(_TAB)
#define TH_ENT num(_ENT)
#define TH_SPC swp(_SPC)
#define TH_BSP ar(_BSPC)
#define TH_REP _REP

// warp combos
#define WARP_H HYPR(KC_W)

enum layers { BSE, SYM, NUM, FUN, NAV, MSE, SYS };

enum custom_keycodes {
    // symbols
    UPDIR = SAFE_RANGE,
    LXHM,
    // alternate repeats (magic key)
    MG_ENT,
    MG_MENT,
    MG_ER,
    MG_ES,
    MG_UST,
    MG_ON,
    MG_ION,
    MG_OA,
    MG_SP_BUT,
    MG_THE,
    MG_EFORE,
    MG_HICH,
};

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
    * │ V │ M │ L │ C │ P │       │ B │ ★ │ U │ O │ Q │
    * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
    * │ S │ T │ R │ D │ Y │       │ F │ N │ E │ A │ I │
    * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
    * │ X │ K │ J │ G │ W │       │ Z │ H │ , │ . │ / │
    * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
    *           ┌───┐                   ┌───┐
    *           │ ? ├───┐           ┌───┤REP│
    *           └───┤TAB├───┐   ┌───┤BSP├───┘
    *               └───┤ENT│   │SPC├───┘
    *                   └───┘   └───┘
    */

    [BSE] = LAYOUT_split_3x5_3(
    //,--------------------------------------------.                    ,--------------------------------------------.
             _V,      _M,      _L,      _C,      _P,                           _B,   _AREP,      _U,      _O,      _Q,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
           HM_S,    HM_T,    HM_R,    HM_D,      _Y,                           _F,    HM_N,    HM_E,    HM_A,    HM_I,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
           HM_X,    HM_K,      _J,      _G,      _W,                           _Z,      _H,   _COMM,   HM_DT,   HM_SL,
    //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                      TH_X,  TH_TAB,  TH_ENT,     TH_SPC,  TH_BSP,  TH_REP
                               //`--------------------------'  `--------------------------'
    ),

    [SYM] = LAYOUT_split_3x5_3(
    //,--------------------------------------------.                    ,--------------------------------------------.
        KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR,                      KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,  KC_GRV,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        ___O___, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR,                      KC_UNDS, KC_MINS, KC_PLUS,  KC_EQL, ___O___,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
           CTRL,     ALT, KC_LBRC, KC_RBRC, KC_DQUO,                      KC_PIPE, KC_QUOT, KC_SCLN, KC_COLN, KC_BSLS,
    //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                   MO(SYS), _______, _______,    _______, _______,   UPDIR
                               //`--------------------------'  `--------------------------'
    ),

    [NUM] = LAYOUT_split_3x5_3(
    //,--------------------------------------------.                    ,--------------------------------------------.
        ___x___, ___x___, ___x___, ___x___, ___x___,                       KC_DOT,    KC_7,    KC_8,    KC_9, KC_COMM,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        ___x___,     SFT,     GUI, ___x___, MO(FUN),                      KC_ASTR,    KC_4,    KC_5,    KC_6, KC_MINS,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
           CTRL,     ALT, ___x___, ___x___, ___x___,                      KC_SLSH,    KC_1,    KC_2,    KC_3, KC_PLUS,
    //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                   ___x___, _______, ___O___,    _______, _______,    KC_0
                               //`--------------------------'  `--------------------------'
    ),

    [FUN] = LAYOUT_split_3x5_3(
    //,--------------------------------------------.                    ,--------------------------------------------.
        ___x___, ___x___, ___x___, ___x___, ___x___,                      ___x___,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        ___x___,     SFT,     GUI, ___x___, ___O___,                      ___x___,   KC_F4,   KC_F5,   KC_F6,  KC_F11,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
           CTRL,     ALT, ___x___, ___x___, ___x___,                      ___x___,   KC_F1,   KC_F2,   KC_F3,  KC_F12,
    //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                   ___x___, ___x___, ___O___,    ___x___, ___x___, ___x___
                               //`--------------------------'  `--------------------------'
    ),

    [NAV] = LAYOUT_split_3x5_3(
    //,--------------------------------------------.                    ,--------------------------------------------.
        ___x___, ___x___, ___x___, ___x___, ___x___,                      ___x___, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        ___x___,     SFT,     GUI, ___O___, ___x___,                      ___x___, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
           CTRL,     ALT, ___x___, ___x___, ___x___,                      ___x___, KC_PSTE, KC_COPY,  KC_CUT,  KC_INS,
    //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                   ___x___, _______, _______,    _______, _______, ___x___
                               //`--------------------------'  `--------------------------'
    ),

    [MSE] = LAYOUT_split_3x5_3(
    //,--------------------------------------------.                    ,--------------------------------------------.
        ___x___, MS_WHLD,   MS_UP, MS_WHLU, ___x___,                      ___x___, ___x___, ___x___, ___x___, ___x___,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        MS_BTN4, MS_LEFT, MS_DOWN, MS_RGHT,  WARP_H,                      ___x___, ___O___, MS_ACL0, MS_ACL1, MS_ACL2,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        MS_BTN5, ___x___, ___x___, ___x___, ___x___,                      ___x___, ___x___, ___x___, ___x___, ___x___,
    //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                   MS_BTN3, MS_BTN2, MS_BTN1,    MS_BTN1, MS_BTN2, MS_BTN3
                               //`--------------------------'  `--------------------------'
    ),

    [SYS] = LAYOUT_split_3x5_3(
    //,--------------------------------------------.                    ,--------------------------------------------.
        ___x___, ___x___, ___x___, ___x___, ___x___,                      ___x___, KC_MPLY, KC_MPRV, KC_MNXT, ___x___,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        ___x___, ___x___, ___x___, ___x___, ___x___,                      ___x___, KC_MUTE, KC_VOLD, KC_VOLU, ___x___,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        ___x___, ___x___, ___x___, ___x___, ___x___,                      ___x___, ___x___, ___x___, ___x___, ___x___,
    //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                   ___x___, ___x___, ___x___,    ___x___, ___x___, ___x___
                               //`--------------------------'  `--------------------------'
    )
};
/* clang-format on */

// ---------- SWAP HANDS MATRIX ------------------------------------------------
#ifdef SWAP_HANDS_ENABLE
__attribute__((weak)) const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    // Left
    {{4, 4}, {3, 4}, {2, 4}, {1, 4}, {0, 4}},
    {{4, 5}, {3, 5}, {2, 5}, {1, 5}, {0, 5}},
    {{4, 6}, {3, 6}, {2, 6}, {1, 6}, {0, 6}},
    {{2, 7}, {1, 7}, {0, 7}},
    // Right
    {{4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
    {{4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
    {{4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
    {{2, 3}, {1, 3}, {0, 3}},
};
#endif

// ---------- CUSTOM KEYCODES, REPEATS, etc. --------------------------------
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // prevent custom shift for arrow keys when used in combination with GUI
    if (record->event.pressed && (get_mods() & MOD_MASK_GUI)) {
        switch (keycode) {
            case KC_LEFT:
            case KC_RIGHT:
            case KC_UP:
            case KC_DOWN:
                return true;
        }
    }

    if (!process_caps_word(keycode, record)) { return false; }
    if (!process_custom_shift_keys(keycode, record)) { return false; }

    if (record->event.pressed) {
        /* custom keycodes */
        switch (keycode) {
            case UPDIR:
                SEND_STRING("../");
                return false;
            case LXHM:
                SEND_STRING("~/");
                return false;
        }

        /* alternate keys */
        int rep_count = get_repeat_key_count();
        uint8_t last_only_shifted = get_last_mods() & ~MOD_MASK_SHIFT;
        // let AREP and REP send n after alternate repeats (with exceptions)
        if (rep_count < 0 && keycode <= KC_Z && last_only_shifted == 0) {
            set_last_keycode(KC_N);
            set_last_mods(0);
        }

        switch (keycode) {
            case MG_ENT:
                SEND_STRING("ent");
                return false;
            case MG_MENT:
                SEND_STRING("ment");
                return false;
            case MG_ER:
                SEND_STRING("er");
                return false;
            case MG_ES:
                SEND_STRING("es");
                return false;
            case MG_UST:
                if (rep_count < -1) {
                    SEND_STRING("ment");
                } else {
                    SEND_STRING("ust");
                }
                return false;
            case MG_OA:
                SEND_STRING("oa");
                return false;
            case MG_ON:
                SEND_STRING("on");
                return false;
            case MG_ION:
                SEND_STRING("ion");
                return false;
            case MG_SP_BUT:
                SEND_STRING(" but");
                return false;
            case MG_THE:
                SEND_STRING("the");
                return false;
            case MG_EFORE:
                SEND_STRING("efore");
                return false;
            case MG_HICH:
                SEND_STRING("hich");
                return false;
        }
    }

    return true;
}

// ---------- CUSTOM SHIFT KEYS ------------------------------------------------
// https://getreuer.info/posts/keyboards/custom-shift-keys/index.html
const custom_shift_key_t custom_shift_keys[] = {
    {TH_BSP, KC_DEL},
    // shifted arrow keys
    {KC_LEFT, KC_HOME},
    {KC_RIGHT, KC_END},
    {KC_UP, KC_PGUP},
    {KC_DOWN, KC_PGDN},
    // invert plus <> equal
    {KC_PLUS, KC_EQL},
};
uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

// ---------- AUTO SHIFT -------------------------------------------------------
// special keys (i.e. symbols) excluded via NO_AUTO_SHIFT_SPECIAL in config.h
// tap-holds need to be added manually
bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    // catch-all tap-holds
    if (IS_RETRO(keycode)) {
        // NOTE:
        // TH_TAB: <- don't enable. we want auto-S+TAB for inverse cycles
        // swp(KC): <- not working. use SYM layer or REP key as workaround
        switch (keycode) {
            // skip auto-shift and allow double-tap-hold->repeat for tap-holds
            case TH_ENT:
            case TH_SPC:
            case TH_BSP:
                return false;
            default:
                return true;
        }
    } else {
        switch (keycode) {
            case KC_DOT:
            case KC_COMM:
                return true;
            default:
                return false;
        }
    }
}

// ---------- KEY COMBOS -------------------------------------------------------
// software reboot
const uint16_t PROGMEM reset_left_combo[] = {_U, _O, _Q, COMBO_END};
const uint16_t PROGMEM reset_right_combo[] = {_V, _M, _L, COMBO_END};
// escape
const uint16_t PROGMEM esc_left_combo[] = {HM_R, _Y, COMBO_END};
const uint16_t PROGMEM esc_right_combo[] = {_F, HM_E, COMBO_END};
// symbols left side
const uint16_t PROGMEM sym_tild_combo[] = {_V, HM_S, COMBO_END};
const uint16_t PROGMEM sym_exlm_combo[] = {_M, HM_T, COMBO_END};
const uint16_t PROGMEM sym_at_combo[] = {_L, HM_R, COMBO_END};
const uint16_t PROGMEM sym_hash_combo[] = {_C, HM_D, COMBO_END};
const uint16_t PROGMEM sym_dlr_combo[] = {_P, _Y, COMBO_END};
const uint16_t PROGMEM sym_perc_combo[] = {HM_S, HM_X, COMBO_END};
const uint16_t PROGMEM sym_circ_combo[] = {HM_T, HM_K, COMBO_END};
const uint16_t PROGMEM sym_ampr_combo[] = {HM_R, _J, COMBO_END};
const uint16_t PROGMEM sym_astr_combo[] = {HM_D, _G, COMBO_END};
const uint16_t PROGMEM sym_grv_combo[] = {_Y, _W, COMBO_END};
// symbols right side
const uint16_t PROGMEM sym_unds_combo[] = {_B, _F, COMBO_END};
const uint16_t PROGMEM sym_mins_combo[] = {_AREP, HM_N, COMBO_END};
const uint16_t PROGMEM sym_plus_combo[] = {_U, HM_E, COMBO_END};
const uint16_t PROGMEM sym_eql_combo[] = {_O, HM_A, COMBO_END};
const uint16_t PROGMEM sym_pipe_combo[] = {_F, _Z, COMBO_END};
const uint16_t PROGMEM sym_quot_combo[] = {HM_N, _H, COMBO_END};
const uint16_t PROGMEM sym_scln_combo[] = {HM_E, _COMM, COMBO_END};
const uint16_t PROGMEM sym_coln_combo[] = {HM_A, HM_DT, COMBO_END};
const uint16_t PROGMEM sym_bsls_combo[] = {HM_I, HM_SL, COMBO_END};

combo_t key_combos[] = {
    // software reboot
    COMBO(reset_left_combo, QK_BOOT),
    COMBO(reset_right_combo, QK_BOOT),
    // escape
    COMBO(esc_left_combo, _ESC),
    COMBO(esc_right_combo, _ESC),
    // symbols left side
    COMBO(sym_tild_combo, KC_TILD),
    COMBO(sym_exlm_combo, KC_EXLM),
    COMBO(sym_at_combo, KC_AT),
    COMBO(sym_hash_combo, KC_HASH),
    COMBO(sym_dlr_combo, KC_DLR),
    COMBO(sym_perc_combo, KC_PERC),
    COMBO(sym_circ_combo, KC_CIRC),
    COMBO(sym_ampr_combo, KC_AMPR),
    COMBO(sym_astr_combo, KC_ASTR),
    COMBO(sym_grv_combo, KC_GRV),
    // symbols right side
    COMBO(sym_unds_combo, KC_UNDS),
    COMBO(sym_mins_combo, KC_MINS),
    COMBO(sym_plus_combo, KC_PLUS),
    COMBO(sym_eql_combo, KC_EQL),
    COMBO(sym_pipe_combo, KC_PIPE),
    COMBO(sym_quot_combo, KC_QUOT),
    COMBO(sym_coln_combo, KC_COLN),
    COMBO(sym_scln_combo, KC_SCLN),
    COMBO(sym_bsls_combo, KC_BSLS),
};

// ---------- (ALTERNATE) REPEATS ----------------------------------------------
/* https://docs.qmk.fm/#/feature_repeat_key */

// unpack tapping keycodes for tap-hold keys
//   https://docs.qmk.fm/#/feature_autocorrect?id=process-autocorrect-example
uint16_t unpack_keycode(uint16_t keycode) {
    switch (keycode) {
        // exclude mod tap-holds when held down and mask for base keycode when only tapped
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            return QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
        // same for layer tap-holds
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            return QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
    }

    return keycode;
}

// https://docs.qmk.fm/#/feature_repeat_key?id=ignoring-certain-keys-and-mods
// bool remember_last_key_user(uint16_t keycode, keyrecord_t *record, uint8_t *remembered_mods) {
//     // forget Shift on letters when Shift or AltGr are the only mods
//     //   https://docs.qmk.fm/#/feature_repeat_key?id=filtering-remembered-mods
//     keycode = unpack_keycode(keycode);
//     switch (keycode) {
//         case KC_A ... KC_Z:
//             if ((*remembered_mods & ~(MOD_MASK_SHIFT | MOD_BIT(KC_RALT))) == 0) {
//                 *remembered_mods &= ~MOD_MASK_SHIFT;
//             }
//             break;
//     }
//
//     return true;
// }

// use alternate repeat concept from magic strdy
//   https://github.com/Ikcelaks/keyboard_layouts/blob/main/magic_sturdy/magic_sturdy.md
uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    /* clang-format off */
    keycode = unpack_keycode(keycode);
    switch (keycode) {
        // SFBs left and scissors -> alternations
        case KC_C: return KC_D;
        case KC_P:
        case KC_D:
        case KC_G: return KC_W;
        case KC_L:
        case KC_S: return KC_K;
        case KC_R: return KC_L;
        // SFBs right -> inward rolls
        case KC_K: return KC_S;
        case KC_Y: return KC_P;
        case KC_N: return KC_N;
        case KC_Z: return KC_H;
        case KC_U: return KC_E;
        case KC_O: return KC_A;
        case KC_E: return KC_U;
        case KC_A: return KC_O;
        // white space & symbols
        case KC_SPC:
        case KC_TAB: return MG_THE;
        case KC_COMM: return MG_SP_BUT;
        case KC_MINS: return KC_RABK;
        // syllables & endings
        case KC_H: return MG_OA;
        case KC_I: return MG_ON;
        case KC_V: return MG_ER;
        case KC_X: return MG_ES;
        case KC_M: return MG_ENT;
        case KC_T: return MG_MENT;
        case KC_J: return MG_UST;
        case KC_B: return MG_EFORE;
        case KC_W: return MG_HICH;
    }

    return KC_TRNS;
    /* clang-format on */
}
