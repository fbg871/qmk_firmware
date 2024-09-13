#include QMK_KEYBOARD_H

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3

enum custom_keycodes {
  LAYER0 = SAFE_RANGE,
  LAYER1,
};

enum combos {
  enter,
  tab,
  esc,
  layer3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_LAYER0] = LAYOUT(
    KC_Q, KC_W, KC_E, KC_R, KC_T,       KC_Y, KC_U, KC_I, KC_O, KC_P,
    KC_A, KC_S, KC_D, KC_F, KC_G,       KC_H, KC_J, KC_K, KC_L, KC_BSPC,
    KC_Z, KC_X, KC_C, KC_V, KC_B,       KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
            MO(1), KC_LEFT_SHIFT,       KC_SPC, MO(2)
   ),

  [_LAYER1] = LAYOUT(
    KC_1, KC_2, KC_3, KC_4, KC_5,       KC_6, KC_7, KC_8, KC_9, KC_0,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                 KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_BSPC,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_LEFT_SHIFT, KC_SPC, MO(2)
  ),

  [_LAYER2] = LAYOUT(
    KC_GRV, KC_NO, KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, KC_NO,        KC_QUOT, KC_LBRC, KC_RBRC, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_BRMD, KC_BRMU, KC_NO,        KC_SCLN, KC_LPRN, KC_RPRN, KC_EQUAL, KC_BSPC,
    KC_LCTL, KC_LALT, KC_LGUI, KC_NO, KC_NO,       KC_BSLS, KC_LT, KC_GT, KC_MINUS, KC_NO,
    MO(1), KC_LEFT_SHIFT, KC_SPC, KC_NO
  ),

  [_LAYER3] = LAYOUT(
          KC_EXLM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERCENT, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
          KC_NO, KC_NO, KC_SPC, KC_NO
          ),
};

const uint16_t PROGMEM enter_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM layer_3_combo[] = {MO(1), MO(2), COMBO_END};

combo_t key_combos[14] = {
  [enter] = COMBO(enter_combo, KC_ENTER),
  [tab] = COMBO(tab_combo, KC_TAB),
  [esc] = COMBO(esc_combo, KC_ESC),
  [layer3] = COMBO(layer_3_combo, MO(3))
};
