#include QMK_KEYBOARD_H

#include "features/custom_shift_keys.h"
#include "macros.h"

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

enum layers { BSE, SYM, NUM, FUN, NAV, MSE, SYS };

enum custom_keycodes {
    UPDIR = SAFE_RANGE,
    LXHM,
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
             _V,      _M,      _L,      _C,      _P,                           _B, ___x___,      _U,      _O,      _Q,
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
                                   ___x___,    LXHM,  KC_ENT,     KC_SPC,   UPDIR, ___x___
                               //`--------------------------'  `--------------------------'
    ),

    [NUM] = LAYOUT_split_3x5_3(
    //,--------------------------------------------.                    ,--------------------------------------------.
        ___x___, ___x___, ___x___, ___x___, ___x___,                      ___x___,    KC_7,    KC_8,    KC_9, ___x___,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        ___x___,     SFT,     GUI, ___x___, MO(FUN),                      KC_ASTR,    KC_4,    KC_5,    KC_6, KC_MINS,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
           CTRL,     ALT, ___x___, ___x___, ___x___,                      KC_SLSH,    KC_1,    KC_2,    KC_3, KC_PLUS,
    //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                   ___x___, ___x___, ___O___,    KC_COMM,  KC_DOT,    KC_0
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
        ___x___, ___x___, ___x___, ___x___, ___x___,                      ___x___, ___x___, ___x___, ___x___, ___x___,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        ___x___,     SFT,     GUI, ___O___, ___x___,                      ___x___, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
           CTRL,     ALT, ___x___, ___x___, ___x___,                      ___x___, KC_PSTE, KC_COPY,  KC_CUT,  KC_INS,
    //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                   ___x___, ___x___, ___x___,    ___x___, ___x___, ___x___
                               //`--------------------------'  `--------------------------'
    ),

    [MSE] = LAYOUT_split_3x5_3(
    //,--------------------------------------------.                    ,--------------------------------------------.
        ___x___, KC_WH_D, KC_MS_U, KC_WH_U, ___x___,                      ___x___, ___x___, ___x___, ___x___, ___x___,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        ___x___, KC_MS_L, KC_MS_D, KC_MS_R, ___x___,                      ___x___, ___O___, KC_ACL0, KC_ACL1, KC_ACL2,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        ___x___, ___x___, ___x___, ___x___, ___x___,                      ___x___, ___x___, ___x___, ___x___, ___x___,
    //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                   KC_BTN3, KC_BTN2, KC_BTN1,    ___x___, KC_BTN4, KC_BTN5
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

// ---------- CUSTOM MACROS ----------------------------------------------------
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_caps_word(keycode, record)) { return false; }
    if (!process_custom_shift_keys(keycode, record)) { return false; }

    /* const uint8_t mods = get_mods(); */
    /* const uint8_t oneshot_mods = get_oneshot_mods(); */
    /* const bool shifted = (mods | oneshot_mods) & MOD_MASK_SHIFT; */

    // for more unicode, see https://github.com/getreuer/qmk-keymap/blob/main/keymap.c
    if (record->event.pressed) {
        switch (keycode) {
            case UPDIR:
                SEND_STRING("../");
                return false;
            case LXHM:
                SEND_STRING("~/");
                return false;
        }
    }

    return true;
}

// ---------- CUSTOM SHIFT KEYS ------------------------------------------------
// https://getreuer.info/posts/keyboards/custom-shift-keys/index.html
const custom_shift_key_t custom_shift_keys[] = {
    {sym(KC_BSPC), KC_DEL},
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
