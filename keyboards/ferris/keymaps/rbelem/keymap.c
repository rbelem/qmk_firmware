#include QMK_KEYBOARD_H
#include "keymap_brazilian_abnt2.h"



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_2(
        KC_Q, KC_W, KC_E, KC_R, KC_T,    KC_Y, KC_U, KC_I,     KC_O,   KC_P,
        KC_A, KC_S, KC_D, KC_F, KC_G,    KC_H, KC_J, KC_K,     KC_L,   BR_TILD,
        KC_Z, KC_X, KC_C, KC_V, KC_B,    KC_N, KC_M, KC_COMMA, KC_DOT, BR_SCLN,
        KC_LCTL, LSFT_T(KC_SPC),         KC_LGUI, LALT_T(LSFT(KC_RALT))
    ),
    [1] = LAYOUT_split_3x5_2(
        KC_1,  KC_2,  KC_3,  KC_4,  KC_5,     KC_6,    KC_7,     KC_8,     KC_9,   KC_0,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    BR_LBRC, KC_MINUS, KC_EQUAL, BR_GRV, BR_QUOT,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    BR_RBRC, BR_BSLS,  KC_COMMA, KC_DOT, BR_SLSH,
        OSM(KC_LCTL), KC_TRNS,                OSM(KC_LGUI), OSM(KC_LALT)
    ),
    [2] = LAYOUT_split_3x5_2(
        KC_NO, KC_NO, KC_KP_SLASH, KC_KP_ASTERISK, KC_NO,    KC_KP_0,     KC_KP_1, KC_KP_2, KC_KP_3, KC_NO,
        KC_NO, KC_NO, KC_KP_MINUS, KC_KP_PLUS,     KC_NO,    KC_KP_DOT,   KC_KP_4, KC_KP_5, KC_KP_6, KC_NO,
        KC_NO, KC_NO, KC_PERCENT,  KC_KP_EQUAL,    KC_NO,    KC_KP_COMMA, KC_KP_7, KC_KP_8, KC_KP_9, KC_NO,
        OSM(KC_LCTL), KC_TRNS,                               OSM(KC_LGUI), OSM(KC_LALT)
    ),
    [3] = LAYOUT_split_3x5_2(
        LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),    LSFT(KC_6),    LSFT(KC_7),     LSFT(KC_8),     LSFT(KC_9),   LSFT(KC_0),
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,         LSFT(BR_LBRC), LSFT(KC_MINUS), LSFT(KC_EQUAL), BR_GRV,       LSFT(BR_QUOT),
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,         LSFT(BR_RBRC), LSFT(BR_BSLS),  LSFT(KC_COMMA), LSFT(KC_DOT), LSFT(BR_SLSH),
        KC_RCTL, KC_TRNS,                                              OSM(KC_LGUI), OSM(KC_LALT)
    ),
    [4] = LAYOUT_split_3x5_2(
        KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, KC_NO,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,
        KC_TRNS, KC_TRNS,                             KC_TRNS, KC_TRNS
    ),
    [5] = LAYOUT_split_3x5_2(
        KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, KC_NO,    KC_WH_L,    KC_WH_D,    KC_WH_U,    KC_WH_R, KC_MS_ACCEL0,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_MS_L,    KC_MS_D,    KC_MS_U,    KC_MS_R, KC_MS_ACCEL1,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_MS_BTN3, KC_MS_BTN4, KC_MS_BTN5, KC_NO,   KC_MS_ACCEL2,
        KC_TRNS, KC_TRNS,                             KC_MS_BTN1, KC_MS_BTN2
    ),
    [6] = LAYOUT_split_3x5_2(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO,   KC_BRID, KC_BRIU, KC_NO,   KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_MUTE, KC_VOLD, KC_VOLU, KC_NO,   KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, KC_NO,
        KC_NO, KC_NO,                         KC_NO, KC_NO
    ),
    [7] = LAYOUT_split_3x5_2(
        KC_NO, OSM(KC_F3), OSM(KC_F2), OSM(KC_F1), OSM(KC_F10),    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, OSM(KC_F6), OSM(KC_F5), OSM(KC_F4), OSM(KC_F11),    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, OSM(KC_F9), OSM(KC_F8), OSM(KC_F7), OSM(KC_F12),    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_TRNS, KC_TRNS,                                          KC_TRNS, KC_TRNS
    ),
    [8] = LAYOUT_split_3x5_2(
        KC_NO, KC_NO,   KC_NO,     KC_NO, OU_BT,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO,   KC_NO,     KC_NO, OU_USB,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, QK_BOOT, QK_REBOOT, KC_NO, OU_AUTO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO,                                 KC_NO, KC_NO
    )
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)





