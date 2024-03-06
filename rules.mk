# bootloader
BOOTLOADER = rp2040

# setup: https://docs.qmk.fm/#/serial_driver?id=setup-1
SPLIT_KEYBOARD = yes
SERIAL_DRIVER = vendor
AUDIO_DRIVER = pwm_hardware

# OLED config
OLED_ENABLE = no
OLED_DRIVER = ssd1306

# Link Time Optimization -> smaller size
LTO_ENABLE = yes

# disable stuff we don't need to further reduce size
# https://docs.qmk.fm/#/squeezing_avr?id=rulesmk-settings
CONSOLE_ENABLE = no         # console for debug
COMMAND_ENABLE = no         # commands for debug and configuration
BACKLIGHT_ENABLE = no       # keyboard backlight functionality
RGBLIGHT_ENABLE = no        # keyboard RGB underglow
SPACE_CADET_ENABLE = no     # braces via shift tapping
GRAVE_ESC_ENABLE = no       # shared ESC / grave key
MAGIC_ENABLE = no           # swapping modifier keys etc.
NKRO_ENABLE = no            # N-Key Rollover
MUSIC_ENABLE = no           # translation from keys to notes
AUDIO_ENABLE = no           # audio output
WPM_ENABLE = no             # make words-per-minute available

# enable special keys
MOUSEKEY_ENABLE = yes       # click, scroll etc.
EXTRAKEY_ENABLE = yes       # audio and system control
UNICODE_ENABLE = yes        # unicode
REPEAT_KEY_ENABLE = yes     # repeats last pressed key

# simplify shifting characters (requires disabled COMMAND feature)
COMMAND_ENABLE = no
CAPS_WORD_ENABLE = yes
AUTO_SHIFT_ENABLE = yes

# enable Getreuer's custom shift keys
SRC += features/custom_shift_keys.c

# enable swap hands feature
SWAP_HANDS_ENABLE = yes

# enable key combos
COMBO_ENABLE = yes
