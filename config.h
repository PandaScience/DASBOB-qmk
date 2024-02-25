// Copyright 2022 grooovebob (@grooovebob)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// ---------- FIRMWARE CONFIG --------------------------------------------------
/* matrix configuration */
#define MATRIX_ROWS 8
#define MATRIX_COLS 5

#define DIRECT_PINS { \
    { GP13, GP28, GP12, GP29, GP0 }, \
    { GP22, GP14, GP26, GP4,  GP27}, \
    { GP21, GP23, GP7, GP20, GP6 }, \
    { GP16, GP9, GP8, NO_PIN, NO_PIN } \
}

#define DIRECT_PINS_RIGHT {  \
    { GP0, GP29, GP12, GP28, GP13 }, \
    { GP27, GP4, GP26, GP14, GP22}, \
    { GP6, GP20, GP7, GP23, GP21 }, \
    { GP8, GP9, GP16, NO_PIN, NO_PIN } \
}

/* serial config */
#define USE_SERIAL
#define SERIAL_USART_TX_PIN GP1

/* I2C pin mapping */
//#define I2C1_SDA_PIN GP7
//#define I2C1_SCL_PIN GP6
//#define I2C1_CLOCK_SPEED 400000
//#define I2C_DRIVER I2CD2

/* auto detect split primary and handedness */
#define SPLIT_USB_DETECT
#define USB_VBUS_PIN 19
#define EE_HANDS

// NOTE:
// for EE_HANDS to work automatically, run once from qmk root path:
//   make dasbob:default:uf2-split-left
//   make dasbob:default:uf2-split-right
// or equivalently
//   qmk flash -kb dasbob -km default -bl uf2-split-left
//   qmk flash -kb dasbob -km default -bl uf2-split-right
// afterwards and after setting some defaults
//   qmk config user.keyboard=dasbob
//   qmk config user.keymap=default
// it's sufficient for either side to run a simple
//   qmk flash

// ---------- FEATURE SETTINGS -------------------------------------------------
/* tap vs hold settings */
#define TAPPING_TERM 200
#undef PERMISSIVE_HOLD
#undef PREVENT_STUCK_MODIFIERS

/* autoshift settings */
#define AUTO_SHIFT_TIMEOUT 150
#define RETRO_SHIFT 500
#define NO_AUTO_SHIFT_SPECIAL

/* combo settings */
#define COMBO_MUST_TAP_PER_COMBO

/* caps word settings */
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

/* mouse key settings */
#define MK_COMBINED  // like accelerated mode but enable constant speed keys
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_TIME_TO_MAX 40
#define MOUSEKEY_MAX_SPEED 5

// ---------- AUDIO CONFIG -----------------------------------------------------
#define AUDIO_PWM_DRIVER PWMD2
#define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_B
#define AUDIO_STATE_TIMER GPTD4
#define AUDIO_PIN GP5
#ifdef AUDIO_ENABLE
    #define AUDIO_INIT_DELAY
    #define AUDIO_CLICKY
    #define AUDIO_CLICKY_FREQ_RANDOMNESS 1.0f
    #define STARTUP_SONG SONG(STARTUP_SOUND)
#endif
#define STARTUP_SOUND E__NOTE(_E6), E__NOTE(_A6), ED_NOTE(_E7),
