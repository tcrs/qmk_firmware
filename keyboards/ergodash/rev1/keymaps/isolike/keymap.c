#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _RAISE 1

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_3key_1us(
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS,          KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,          KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
     KC_NUBS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,          KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ENT,           KC_ENT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NUHS,
     KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL,       MO(_RAISE), KC_SPC,           KC_SPC,  MO(_RAISE),       KC_RCTL, KC_RALT, KC_APP,  KC_RSFT
  ),

  [_RAISE] = LAYOUT_3key_1us(
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,          _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
     KC_INS,  KC_HOME, KC_UP,   KC_END,  _______, KC_PGUP, _______,          _______, KC_WH_U, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_INS,
     _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_PGDN, CMB_TOG,          _______, KC_WH_D, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
     _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______, _______,          _______, _______, _______, _______, _______, _______, KC_GRV,
     _______, KC_RGUI, _______, _______,          _______, _______,          _______, _______,          _______, _______, _______, _______
  )
};

enum combos {
  COMBO_LBRC,
  COMBO_RBRC,
  COMBO_UNDS,
  COMBO_EQL,
};

#define COMBO_DECL2(name, k0, k1) \
  const uint16_t PROGMEM combo_ ## name[] = { KC_ ## k0, KC_ ## k1, COMBO_END }

COMBO_DECL2(lbrc, M, COMM);
COMBO_DECL2(rbrc, COMM, DOT);
COMBO_DECL2(unds, L, SCLN);
COMBO_DECL2(equal, SLSH, NUHS);

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_LBRC] = COMBO(combo_lbrc, KC_LBRC),
  [COMBO_RBRC] = COMBO(combo_rbrc, KC_RBRC),
  [COMBO_UNDS] = COMBO(combo_unds, KC_UNDS),
  [COMBO_EQL] = COMBO(combo_equal, KC_EQL),
};
