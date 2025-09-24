/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
 * Copyright 2023 casuanoob <casuanoob@hotmail.com> (@casuanoob)
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

enum dilemma_keymap_layers {
    LAYER_BASE = 0,
    LAYER_SYMBOLS,
    LAYER_NUMBERS,
    LAYER_FUNCTION,
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

// left half - layer 4 tap
#define LT_4TAB LT(LAYER_POINTER, KC_TAB)

// left half - layer 3 tap
#define LT_3T LT(3, KC_T)

// right half - layer 3 tap
#define RT_3Y LT(3, KC_Y)

// left half - layer 2 tap
#define LT_2G LT(2, KC_G)

// right half - layer 2 tap
#define RT_2H LT(2, KC_H)

// left half - layer 1 tap
#define LT_1ENT LT(1, KC_ENT)

// right half - layer 1 tap
#define RT_1SPC LT(1, KC_SPC)

// left half - left GUI + left control
#define L_GUICTL LGUI(KC_LCTL)

// right half - right GUI + right control
#define R_GUICTL RGUI(KC_RCTL)

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
  [LAYER_BASE] = LAYOUT_split_3x5_3(
          L_GUICTL,  KC_W,  KC_E,  KC_R, LT_3T,       RT_3Y,   KC_U,  KC_I,  KC_O,    R_GUICTL,
             LH0_1, LH0_2, LH0_3, LH0_4, LT_2G,       RT_2H,   RH0_1, RH0_2, RH0_3,   RH0_4,
              KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,       KC_N,    KC_M,  KC_Q,  KC_COMM, KC_DOT,
                     KC_CAPS, LT_4TAB, LT_1ENT,       RT_1SPC, RH_5,  KC_MEH
  ),
  [LAYER_SYMBOLS] = LAYOUT_split_3x5_3(
    KC_PLUS, KC_PIPE, KC_QUES, KC_UNDS, KC_DQUO,        KC_EXLM, KC_AT,    KC_HASH, KC_DLR,  KC_COLN,
      LH1_1, KC_BSLS, KC_SLSH, KC_MINS, KC_QUOT,        KC_PERC, KC_CIRC,  KC_AMPR, KC_ASTR, RH1_1,
    KC_TILD, KC_LPRN, KC_LCBR, KC_LBRC,   KC_LT,        KC_GT,   KC_RBRC,  KC_RCBR, KC_RPRN, KC_GRV,
                        KC_NO, KC_TRNS, KC_TRNS,        CTRLSHFT, ALTSHFT, KC_NO
  ),
  [LAYER_NUMBERS] = LAYOUT_split_3x5_3(
      KC_NO,  KC_7,  KC_8,  KC_9, KC_NO,        KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,
    KC_LGUI, LH2_1, LH2_2, LH2_3, KC_NO,        KC_NO,   KC_RALT, KC_RCTL, KC_RSFT, KC_RGUI,
       KC_0,  KC_1,  KC_2,  KC_3, KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                  KC_NO, OSSHFT, OSCTRL,        CTRLSHFT, ALTSHFT, KC_NO
  ),
  [LAYER_FUNCTION] = LAYOUT_split_3x5_3(
    KC_F12, KC_F7, KC_F8, KC_F9, KC_NO,        KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,
     LH3_1, LH3_2, LH3_3, LH3_4, KC_NO,        KC_MUTE, RH3_1,   RH3_2,   KC_RSFT, KC_RGUI,
    KC_F10, KC_F1, KC_F2, KC_F3, KC_NO,        KC_MPLY, KC_MRWD, KC_MFFD, KC_MSTP, KC_NO,
               KC_NO, KC_TRNS, RGB_TOG,        KC_TRNS, KC_TRNS, KC_NO
  ),
  [LAYER_POINTER] = LAYOUT_split_3x5_3(
      KC_MEH,  KC_HYPR, DRGSCRL,   KC_NO,   KC_NO,        SNIPING, KC_NO, KC_NO, KC_NO, KC_NO,
    CTRLSHFT,  KC_BTN2, KC_LCTL, KC_BTN1, KC_BTN3,        KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
     KC_LALT,  KC_LSFT, ALTSHFT,   KC_NO,   KC_NO,        KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
                              KC_NO, KC_NO, KC_NO,        KC_NO,   KC_NO, KC_NO
  ),
  [LAYER_MISC] = LAYOUT_split_3x5_3(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, QK_BOOT, QK_CLEAR_EEPROM,       QK_CLEAR_EEPROM, QK_BOOT, KC_NO
  ),
};
// clang-format on

#ifdef POINTING_DEVICE_ENABLE
#    ifdef DILEMMA_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    dilemma_set_pointer_sniping_enabled(layer_state_cmp(state, DILEMMA_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // DILEMMA_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

// combos
const uint16_t PROGMEM combo_backspace[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_escape[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_rhalf_uparrow[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_rhalf_downarrow[] = {KC_M, KC_Q, COMBO_END};
const uint16_t PROGMEM combo_rhalf_rightarrow[] = {KC_Q, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_rhalf_leftarrow[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM combo_lhalf_uparrow[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_lhalf_downarrow[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_lhalf_rightarrow[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM combo_lhalf_leftarrow[] = {KC_X, KC_C, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_backspace, KC_BSPC),
    COMBO(combo_escape, KC_ESC),
    COMBO(combo_rhalf_uparrow, KC_UP),
    COMBO(combo_rhalf_downarrow, KC_DOWN),
    COMBO(combo_rhalf_rightarrow, KC_RIGHT),
    COMBO(combo_rhalf_leftarrow, KC_LEFT),
    COMBO(combo_lhalf_uparrow, KC_UP),
    COMBO(combo_lhalf_downarrow, KC_DOWN),
    COMBO(combo_lhalf_rightarrow, KC_RIGHT),
    COMBO(combo_lhalf_leftarrow, KC_LEFT),
};
