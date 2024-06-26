#define _A KC_A
#define _B KC_B
#define _C KC_C
#define _D KC_D
#define _E KC_E
#define _F KC_F
#define _G KC_G
#define _H KC_H
#define _I KC_I
#define _J KC_J
#define _K KC_K
#define _L KC_L
#define _M KC_M
#define _N KC_N
#define _O KC_O
#define _P KC_P
#define _Q KC_Q
#define _R KC_R
#define _S KC_S
#define _T KC_T
#define _U KC_U
#define _V KC_V
#define _W KC_W
#define _X KC_X
#define _Y KC_Y
#define _Z KC_Z

#define _ESC  KC_ESC
#define _ENT  KC_ENT
#define _SPC  KC_SPC
#define _DEL  KC_DEL
#define _DOT  KC_DOT
#define _TAB  KC_TAB
#define _BSPC KC_BSPC
#define _COMM KC_COMM
#define _SLSH KC_SLSH
#define _SCLN KC_SCLN
#define _QUOT KC_QUOT

// NOTE: will not work as tap-hold!
#define _REP QK_REP
#define _AREP QK_AREP

#define sl(KC) LSFT_T(KC)
#define sr(KC) RSFT_T(KC)
#define cl(KC) LCTL_T(KC)
#define cr(KC) RCTL_T(KC)
#define al(KC) LALT_T(KC)
#define ar(KC) ALGR_T(KC)
#define gl(KC) LGUI_T(KC)
#define gr(KC) RGUI_T(KC)

#define sc(KC) RCS_T(KC)
#define sg(KC) LSG_T(KC)

#define CTRL   KC_LCTL
#define SFT    KC_LSFT
#define ALT    KC_LALT
#define GUI    KC_LGUI
#define S_CTRL S(KC_LCTL)
#define S_ALT  S(KC_LALT)
#define S_GUI  S(KC_LGUI)
