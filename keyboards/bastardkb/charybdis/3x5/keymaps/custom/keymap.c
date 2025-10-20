/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_SYMBOLS,
    LAYER_NUMBERS,
    LAYER_FUNCTIONS,
    LAYER_NAVIGATION,
    LAYER_POINTER,
    LAYER_MISC,
};

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

// left half mod tap (layer 0)
#define LH0_1 MT(MOD_LGUI, KC_A)
#define LH0_2 MT(MOD_LSFT, KC_S)
#define LH0_3 MT(MOD_LCTL, KC_D)
#define LH0_4 MT(MOD_LALT, KC_F)

// left half mod tap (layer 1)
#define LH1_1 MT(MOD_LCTL, KC_EQL)

// left half mod tap (layer 2)
#define LH2_1 MT(MOD_LSFT, KC_4)
#define LH2_2 MT(MOD_LCTL, KC_5)
#define LH2_3 MT(MOD_LALT, KC_6)

// left half mod tap (layer 3)
#define LH3_1 MT(MOD_LGUI, KC_F11)
#define LH3_2 MT(MOD_LSFT, KC_F4)
#define LH3_3 MT(MOD_LCTL, KC_F5)
#define LH3_4 MT(MOD_LALT, KC_F6)

// right half mod tap (layer 0)
#define RH0_1 MT(MOD_RALT, KC_J)
#define RH0_2 MT(MOD_RCTL, KC_K)
#define RH0_3 MT(MOD_RSFT, KC_L)
#define RH0_4 MT(MOD_RGUI, KC_P)
#define RH_5 MEH_T(KC_DEL)

// right half mod tap (layer 1)
#define RH1_1 MT(MOD_LCTL, KC_SCLN)

// right half mod tap (layer 3)
#define RH3_1 MT(MOD_RALT, KC_VOLD)
#define RH3_2 MT(MOD_RCTL, KC_VOLU)

// left half - symbols layer tap
#define LT_SYMBOLS_ENT LT(LAYER_SYMBOLS, KC_ENT)

// right half - symbols layer tap
#define RT_SYMBOLS_SPC LT(LAYER_SYMBOLS, KC_SPC)

// left half - number layer tap
#define LT_NUMBERS_G LT(LAYER_NUMBERS, KC_G)

// right half - number layer tap
#define RT_NUMBERS_H LT(LAYER_NUMBERS, KC_H)

// left half - functions layer tap
#define LT_FUNTIONS_T LT(LAYER_FUNCTIONS, KC_T)

// right half - functions layer tap
#define RT_FUNCTIONS_Y LT(LAYER_FUNCTIONS, KC_Y)

// left half - navigation layer tap
#define LT_NAVIGATION_CAPS LT(LAYER_NAVIGATION, KC_CAPS)

// left half - pointer layer tap
#define LT_POINTER_TAB LT(LAYER_POINTER, KC_TAB)

// left half - misc layer tap
#define LT_MISC_DOT LT(LAYER_MISC, KC_DOT)

// right half - misc layer tap
#define LT_MISC_Z LT(LAYER_MISC, KC_Z)

// left control + left shift
#define CTRLSHFT LCTL(KC_LSFT)

// left OS + left shift
#define OSSHFT LGUI(KC_LSFT)

// left alt + left shift
#define ALTSHFT LALT(KC_LSFT)

// left OS + left ctrl
#define OSCTRL LGUI(KC_LCTL)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
            KC_ESC,  KC_W,  KC_E,  KC_R, LT_FUNTIONS_T,       RT_FUNCTIONS_Y, KC_U,  KC_I,  KC_O,    KC_BSPC,
             LH0_1, LH0_2, LH0_3, LH0_4,  LT_NUMBERS_G,       RT_NUMBERS_H,   RH0_1, RH0_2, RH0_3,   RH0_4,
         LT_MISC_Z,  KC_X,  KC_C,  KC_V,          KC_B,       KC_N,           KC_M,  KC_Q,  KC_COMM, LT_MISC_DOT,
    LT_NAVIGATION_CAPS, LT_POINTER_TAB, LT_SYMBOLS_ENT,       RT_SYMBOLS_SPC, RH_5
  ),
  [LAYER_SYMBOLS] = LAYOUT(
    KC_PLUS, KC_PIPE, KC_QUES, KC_UNDS, KC_DQUO,        KC_EXLM, KC_AT,    KC_HASH, KC_DLR,  KC_COLN,
      LH1_1, KC_BSLS, KC_SLSH, KC_MINS, KC_QUOT,        KC_PERC, KC_CIRC,  KC_AMPR, KC_ASTR, RH1_1,
    KC_TILD, KC_LPRN, KC_LCBR, KC_LBRC,   KC_LT,        KC_GT,   KC_RBRC,  KC_RCBR, KC_RPRN, KC_GRV,
                        KC_NO, KC_TRNS, KC_TRNS,        CTRLSHFT, ALTSHFT
  ),
  [LAYER_NUMBERS] = LAYOUT(
      KC_NO,  KC_7,  KC_8,  KC_9, KC_NO,        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_LGUI, LH2_1, LH2_2, LH2_3, KC_NO,        KC_NO, KC_RALT, KC_RCTL, KC_RSFT, KC_RGUI,
       KC_0,  KC_1,  KC_2,  KC_3, KC_NO,        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
                  KC_NO, OSSHFT, OSCTRL,        CTRLSHFT, ALTSHFT
  ),
  [LAYER_FUNCTIONS] = LAYOUT(
    KC_F12, KC_F7, KC_F8, KC_F9, KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
     LH3_1, LH3_2, LH3_3, LH3_4, KC_NO,        KC_MUTE, RH3_1,   RH3_2,   KC_RSFT, KC_RGUI,
    KC_F10, KC_F1, KC_F2, KC_F3, KC_NO,        KC_MPLY, KC_MRWD, KC_MFFD, KC_MSTP, KC_NO,
               KC_NO, KC_TRNS, RGB_TOG,        KC_TRNS, KC_TRNS
  ),
  [LAYER_NAVIGATION] = LAYOUT(
     OSCTRL,    KC_NO,   KC_NO,   KC_NO, KC_NO,       KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_NO,
    KC_LGUI,  KC_LSFT, KC_LCTL, KC_LALT, KC_NO,       KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_NO,
    KC_NO,      KC_NO,   KC_NO,   KC_NO, KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,
                           KC_NO, KC_NO, KC_NO,       KC_NO,   KC_NO
  ),
  [LAYER_POINTER] = LAYOUT(
      KC_MEH,  KC_HYPR, DRGSCRL,   KC_NO,   KC_NO,        SNIPING, KC_NO, KC_NO, KC_NO, KC_NO,
    CTRLSHFT,  KC_BTN2, KC_LCTL, KC_BTN1, KC_BTN3,        KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
     KC_LALT,  KC_LSFT, ALTSHFT,   KC_NO,   KC_NO,        KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
                              KC_NO, KC_NO, KC_NO,        KC_NO,   KC_NO
  ),
  [LAYER_MISC] = LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, QK_BOOT, QK_CLEAR_EEPROM,       QK_CLEAR_EEPROM, QK_BOOT
  ),
};
// clang-format on
