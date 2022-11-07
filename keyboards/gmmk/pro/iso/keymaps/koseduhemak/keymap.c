/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "rgb_matrix_map.h"
#include "led.c"

enum layers { WIN, MAC, MODS };

enum custom_keycodes {
#ifdef VIA_ENABLE
    KC_ENCODERKNOB = USER00,
#else
    KC_ENCODERKNOB = SAFE_RANGE,
#endif
    KC_MISSION_CONTROL,
    KC_LAUNCHPAD
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]                          PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "        #        Enter             PgDn
//      Sh_L     /        Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backspace. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [WIN] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  TG(MAC),          KC_ENCODERKNOB,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   KC_PGUP,
        LT(MODS, KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           KC_PGDN,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(MODS),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [MAC] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  TG(MAC),          KC_ENCODERKNOB,
        KC_NUBS,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   KC_PGUP,
        LT(MODS, KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           KC_PGDN,
        KC_LSFT, KC_GRV, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RALT, _______,   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [MODS] = LAYOUT(
        _______, KC_BRID, KC_BRIU, KC_MISSION_CONTROL, KC_LAUNCHPAD, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, KC_WFAV, _______,          _______,
        _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,            _______,
        _______, _______, KC_W, _______, _______, _______, _______, _______, KC_UP, _______, _______, _______, RGB_VAI,                   _______,
        _______, _______, KC_S, _______, _______, _______, _______, KC_LEFT,    KC_DOWN,    KC_RIGHT,    _______, _______, _______, _______,          _______,
        _______, _______, _______, RGB_HUI, _______, _______, _______, NK_TOGG, _______, _______, _______, RGB_VAD,          _______, RGB_MOD, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),

};
// clang-format on

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t mods_state = get_mods();
    if (mods_state & MOD_BIT(KC_LCTL)) { // If you are holding L shift, encoder changes layers
        unregister_mods(MOD_BIT(KC_LCTL));

        if (clockwise)
            tap_code(KC_MNXT);
        else
            tap_code(KC_MPRV);

        register_mods(MOD_BIT(KC_LCTL));
    } else if (mods_state & MOD_BIT(KC_RSFT)) { // If you are holding R shift, Page up/dn
        unregister_mods(MOD_BIT(KC_RSFT));
        if (clockwise)
            tap_code16(KC_PGUP);
        else
            tap_code16(KC_PGDN);
        register_mods(MOD_BIT(KC_RSFT));
    } else if (mods_state & MOD_BIT(KC_LGUI)) { // if holding Left Shift, navigate next/prev word
        unregister_mods(MOD_BIT(KC_LGUI));

        if (clockwise)
            tap_code16(LCTL(KC_RGHT));
        else
            tap_code16(LCTL(KC_LEFT));

        register_mods(MOD_BIT(KC_LGUI));
    } else if (mods_state & MOD_BIT(KC_RCTL)) { // if holding Right Ctrl, change rgb hue/colour
        if (clockwise)
            rgblight_increase_hue();
        else
            rgblight_decrease_hue();
    } else if (mods_state & MOD_BIT(KC_LSFT)) { // if holding Left Alt, change brightness up and down
        unregister_mods(MOD_BIT(KC_LSFT));
        if (clockwise) {
            tap_code(KC_BRIU);
        } else {
            tap_code(KC_BRID);
        }
        register_mods(MOD_BIT(KC_LSFT));

        return false;

    } else {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        } // Otherwise it just changes volume
    }
    return true;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mods_state = get_mods();

    switch (get_highest_layer(layer_state | default_layer_state)) {
        case WIN:
        case MAC:
            switch (keycode) {
                case KC_ENCODERKNOB:
                    // if left control is held while pressing the knob, play / pause media playback
                    if (mods_state & MOD_BIT(KC_LCTL)) {
                        if (record->event.pressed) {
                            unregister_mods(MOD_BIT(KC_LCTL));
                            tap_code(KC_MPLY);
                            register_mods(MOD_BIT(KC_LCTL));
                        } else {
                            host_consumer_send(0);
                        }
                        return false;
                    } else {
                        // if no modifier or other modifiers held, just mute
                        if (record->event.pressed) {
                            tap_code(KC_MUTE);
                        } else {
                            host_consumer_send(0);
                        }
                        return false;
                    }
                    break;
                case KC_BSPC:
                    if (mods_state & MOD_BIT(KC_LSFT)) {
                        // if left shift is held and backspace is pressed simulate mac behavior and delete NEXT character
                        if (record->event.pressed) {
                            unregister_mods(MOD_BIT(KC_LSFT));
                            tap_code(KC_DEL);
                            register_mods(MOD_BIT(KC_LSFT));
                        } else {
                            host_consumer_send(0);
                        }
                        return false;
                    }
                    break;
            }
            break;
        case MODS:
            switch (keycode) {
                // send special key code to make MissionControl work on mac
                case KC_MISSION_CONTROL:
                    if (record->event.pressed) {
                        host_consumer_send(0x29F);
                    } else {
                        host_consumer_send(0);
                    }
                    return false; // Skip all further processing of this key
                // send special key code to make LaunchPad work on mac
                case KC_LAUNCHPAD:
                    if (record->event.pressed) {
                        host_consumer_send(0x2A0);
                    } else {
                        host_consumer_send(0);
                    }
                    return false; // Skip all further processing of this key
                // control RGB lightning
                case KC_C:
                    if (record->event.pressed) {
                        rgblight_sethsv_noeeprom(HSV_GOLD);
                    }
                    return false;
                case KC_W:
                    if (record->event.pressed) {
                        rgblight_sethsv_noeeprom(HSV_WHITE);
                    }
                    return false;
            }
    }

    return true;
}

#ifdef RGB_MATRIX_ENABLE
// RGB
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // uint8_t mods_state = get_mods();
    switch (get_highest_layer(layer_state)) { // special handling per layer
        case MODS:                            // on Fn layer select what the encoder does when pressed
            highlight_fkeys();
            break;
    }

    if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
        rgb_matrix_set_color(LED_L4, RGB_RED);
        rgb_matrix_set_color(LED_L5, RGB_RED);
        rgb_matrix_set_color(LED_L6, RGB_RED);
        rgb_matrix_set_color(LED_L7, RGB_RED);
    }
}
#endif
