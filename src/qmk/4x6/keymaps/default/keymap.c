#include QMK_KEYBOARD_H
#include "keymap_bepo.h"

extern keymap_config_t keymap_config;

#define _BASE 0
#define _RAISE 1
#define _LOWER 2

// Fillers to make layering more clear

#define ____ KC_TRNS

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN1

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_BASE] = LAYOUT( \
    KC_TAB,  BP_B,  BP_E_ACUTE, BP_P,   BP_O,   BP_E_GRAVE,               BP_DCRC, BP_V,   BP_D,   BP_L,   BP_J,   BP_Z,    \
    KC_LSFT,  BP_A,  BP_U,       BP_I,   BP_E,   BP_COMMA,                BP_C,    BP_T,   BP_S,   BP_R,   BP_N,   BP_M,    \
    KC_LCTL, BP_W,  BP_Y,       BP_X,   BP_DOT, BP_K,                     BP_APOS, BP_Q,   BP_G,   BP_H,   BP_F,   KC_LCTL, \
                    BP_LCBR, BP_RCBR, MO(LOWER),                          MO(RAISE), BP_LPRN, BP_RPRN,                    \
                    KC_LGUI, KC_ESC,    KC_DEL, KC_ENT,                 KC_SPC,      KC_BSPACE,   _______, KC_LALT                                \
),

[_RAISE] = LAYOUT(
    S(BP_DOLLAR), BP_DOLLAR, BP_DQOT, BP_LCBR, BP_RCBR, _______,             BP_AT, BP_PLUS, BP_MINUS, BP_SLASH, BP_ASTR, BP_EQUAL,   \
    _______,BP_LESS, BP_GRTR  ,BP_LPRN, BP_RPRN,RALT(BP_P),            BP_CCED,KC_LEFT, KC_DOWN, KC_UP , KC_RGHT,_______,   \
    _______,BP_AGRV,_______,_______, BP_PERC ,_______,            BP_AT, BP_PLUS, BP_MINUS, BP_SLASH, BP_ASTR, BP_EQUAL,   \
                    BP_LCBR, BP_RCBR, MO(LOWER),                          MO(RAISE), BP_LPRN, BP_RPRN,                    \
                    _______, KC_ESC,    KC_DEL, BP_UNDS,                 BP_UNDS,      KC_BSPACE,   _______, RESET                                \
),

[_LOWER] = LAYOUT(
    _______, _______, _______, _______, _______, _______,             _______, S(BP_PLUS), S(BP_MINUS), S(BP_SLASH), S(BP_ASTR), _______,   \
    _______,RALT(BP_B), BP_BSLS, BP_LBRC, BP_RBRC,S(BP_PERC),            _______,S(BP_LPRN), S(BP_RPRN), S(BP_AT),_______,_______,   \
    _______,_______, _______, _______,_______,_______,            _______,S(BP_DQOT), S(BP_LGIL), S(BP_RGIL),_______,_______,   \
                    BP_LCBR, BP_RCBR, MO(LOWER),                          MO(RAISE), BP_LPRN, BP_RPRN,                    \
                    RESET, KC_ESC,    KC_DEL, BP_UNDS,                 BP_UNDS,      KC_BSPACE,   _______, _______                                \
)

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
      tap_code(KC_PGDN);
    } else {
      tap_code(KC_PGUP);
    }
}
