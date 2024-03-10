/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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
#include "rgblight.h"

enum custom_keycodes {
    DIS_RGB = SAFE_RANGE,
};

bool disable_rgb = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case DIS_RGB:
        if (record->event.pressed) {
            // when pressed, disable RGB light
            disable_rgb = !disable_rgb;
        } else {
            // when keycode is released
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base Layer
        [0] = LAYOUT_split_3x6_3(
        TG(4),      KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,               KC_LBRC,
        KC_VOLU,    LGUI_T(KC_A),   LALT_T(KC_S),   LCTL_T(KC_D),   LSFT_T(KC_F),   KC_G,                                           KC_H,           RSFT_T(KC_J),   RCTL_T(KC_K),   RALT_T(KC_L),   RGUI_T(KC_SCLN),    KC_QUOT,
        KC_VOLD,    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,           DIS_RGB,
                                                                    KC_ESC,         LT(2,KC_SPC),   KC_TAB,    LT(3,KC_ENT),  LT(1,KC_BSPC),  KC_DEL
    ),
    // Numbers Layer momentarily activated by tapping backspace
        [1] = LAYOUT_split_3x6_3(
        KC_TRNS,    KC_TRNS,        KC_P7,          KC_P8,          KC_P9,          KC_TRNS,                            RALT(KC_LBRC),  KC_TRNS,            KC_UP,              KC_TRNS,            RALT(KC_RBRC),      KC_TRNS,
        KC_NUM,     KC_TRNS,        LGUI_T(KC_P4),  LALT_T(KC_P5),  LCTL_T(KC_P6),  KC_TRNS,                            LSFT(KC_8),     RSFT_T(KC_LEFT),    RCTL_T(KC_DOWN),    RALT_T(KC_RIGHT),   LSFT(KC_9),         KC_TRNS,
        KC_TRNS,    KC_TRNS,        KC_P1,          KC_P2,          KC_P3,          KC_TRNS,                            RALT(KC_QUOT),  KC_PPLS,            KC_PEQL,            KC_PMNS,            RALT(KC_NUHS),      KC_TRNS,
                                                                    KC_TRNS,        KC_P0,      KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS
    ),
    // Symbol Layer momentarily activated by tapping space
        [2] = LAYOUT_split_3x6_3(
        KC_TRNS,    RALT(KC_E),         RALT(KC_8),     RALT(KC_6),     LSFT(KC_4),         RALT(KC_1),                             RALT(KC_2), RALT(KC_3),     LSFT(KC_3),     LSFT(KC_5),     LSFT(KC_6),     KC_TRNS,
        KC_TRNS,    LSFT(KC_2),         RALT(KC_MINS),  LCTL_T(KC_RBRC),LSFT_T(KC_MINS),    LSFT(KC_GRV),                           RALT(KC_7), LSFT(KC_7),     RALT(KC_NUBS),  LSFT(KC_RBRC),  LSFT(KC_MINS),  KC_TRNS,
        KC_TRNS,    LSFT(KC_NUHS),      KC_GRV,         LSFT(KC_EQL),   KC_TRNS,            KC_TRNS,                                KC_NUBS,    LSFT(KC_NUBS),  KC_NUHS,        RALT(KC_EQL),   KC_EQL,         KC_TRNS,
                                                                        KC_TRNS,            KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
    ),
    // Function Layer momentarily activated by tapping enter
        [3] = LAYOUT_split_3x6_3(
        KC_TRNS,    KC_F12,         KC_F7,          KC_F8,          KC_F9,          KC_TRNS,                            KC_TRNS,    KC_PSCR,        KC_SCRL,        KC_PAUS,        KC_TRNS,            KC_TRNS,
        KC_TRNS,    LGUI_T(KC_F11), LALT_T(KC_F4),  LCTL_T(KC_F5),  LSFT_T(KC_F6),  KC_TRNS,                            KC_TRNS,    RSFT_T(KC_INS), RCTL_T(KC_HOME),RALT_T(KC_PGUP),RGUI_T(KC_CAPS),    KC_TRNS,
        KC_TRNS,    KC_F10,         KC_F1,          KC_F2,          KC_F3,          KC_TRNS,                            KC_TRNS,    KC_DEL,         KC_END,         KC_PGDN,        KC_TRNS,            KC_TRNS,
                                                                    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
    ),
    // Gaming Layer (same keys as base layer without home row modifiers) toggled by tapping tab
        [4] = LAYOUT_split_3x6_3(
        TO(0),      KC_Q,   KC_W,   KC_E,   KC_R,       KC_T,                               KC_Y,       KC_U,   KC_I,       KC_O,   KC_P,       KC_LBRC,
        KC_TRNS,    KC_A,   KC_S,   KC_D,   KC_F,       KC_G,                               KC_H,       KC_J,   KC_K,       KC_L,   KC_SCLN,    KC_QUOT,
        KC_TRNS,    KC_Z,   KC_X,   KC_C,   KC_V,       KC_B,                               KC_N,       KC_M,   KC_COMM,    KC_DOT, KC_SLSH,    KC_TRNS,
                                            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
    )
};

bool led_update_user(led_t led_state) {
    if (disable_rgb) {
        // OFF is static black
        rgblight_mode(0);
        rgblight_sethsv(HSV_OFF);
    } else {
        rgblight_mode(2);
        // layer state
        switch (get_highest_layer(layer_state)) {
            case 0:
                rgblight_sethsv(HSV_CYAN);
                break;
            case 1:
                rgblight_sethsv(HSV_YELLOW);
                break;
            case 2:
                rgblight_sethsv(HSV_BLUE);
                break;
            case 3:
                rgblight_sethsv(HSV_RED);
                break;
            case 4:
                rgblight_sethsv(HSV_GREEN);
                break;
        }
    }

    return true;
}

void keyboard_post_init_user(void) {
    //rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR); // RGB_MATRIX_SOLID_COLOR, RGB_MATRIX_BREATHING, RGB_MATRIX_SPLASH, RGB_MATRIX_SOLID_SPLASH
    
    // RGB LED control
    // See rgblight.h for modes

    // OFF is static black
    //rgblight_mode(0);
    //rgblight_sethsv(HSV_OFF);

    // Breathe effect is 2 (see config.h for details)
    rgblight_mode(2);
    rgblight_sethsv(HSV_CYAN);
};
