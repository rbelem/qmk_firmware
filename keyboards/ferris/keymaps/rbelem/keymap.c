#include QMK_KEYBOARD_H
#include "keymap_brazilian_abnt2.h"
#include "features/tap_dance.h"
#include "keymap.h"

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

enum custom_keycodes {
  ALT_TAB = SAFE_RANGE,
};

enum combos {
  W_E_ESC,
  E_R_TAB,
  R_F_ALT_TAB,
  Q_A_NAV_LAYER,
  G_B_BASE_LAYER,
  A_Z_SYS_LAYER,
  Y_U_INSERT,
  U_I_DELETE,
  I_O_BSPC,
  K_L_ENTER,
  Y_N_PSCR,
  Y_H_NAV_LAYER,
  H_N_MOS_LAYER,
  P_TILD_KPD_LAYER,
  TILD_SCLN_MED_LAYER,
  G_H_CAPSWORD,
  B_N_PAUSE
};

const uint16_t PROGMEM w_e_esc[] = { KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM e_r_tab[] = { KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM r_f_alt_tab[] = { KC_R, KC_F, COMBO_END};

const uint16_t PROGMEM q_a_nav_layer[] = { KC_Q, KC_A, COMBO_END };
const uint16_t PROGMEM g_b_base_layer[] = { KC_G, KC_B, COMBO_END };
const uint16_t PROGMEM a_z_sys_layer[] = { KC_A, KC_Z, COMBO_END };


const uint16_t PROGMEM y_u_insert[] = { KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM u_i_delete[] = { KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM i_o_bspc[] = { KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM k_l_enter[] = { KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM y_n_pscr[] = { KC_Y, KC_N, COMBO_END };

const uint16_t PROGMEM y_h_nav_layer[] = { KC_Y, KC_H, COMBO_END };
const uint16_t PROGMEM h_n_mos_layer[] = { KC_H, KC_N, COMBO_END };
const uint16_t PROGMEM p_tild_kpd_layer[] = { KC_P, BR_TILD, COMBO_END };
const uint16_t PROGMEM tild_scln_med_layer[] = { BR_TILD, BR_SCLN, COMBO_END };


const uint16_t PROGMEM g_h_capsword[] = { KC_G, KC_H, COMBO_END };
const uint16_t PROGMEM b_n_pause[] = { KC_B, KC_N, COMBO_END };


combo_t key_combos[COMBO_COUNT] = {
  [W_E_ESC] = COMBO(w_e_esc, KC_ESC),
  [E_R_TAB] = COMBO(e_r_tab, KC_TAB),
  [R_F_ALT_TAB] = COMBO(r_f_alt_tab, ALT_TAB),

  [Q_A_NAV_LAYER] = COMBO(q_a_nav_layer, MO(NAV)),
  [G_B_BASE_LAYER] = COMBO(g_b_base_layer, TO(BAS)),
  [A_Z_SYS_LAYER] = COMBO(a_z_sys_layer, OSL(SYS)),


  [Y_U_INSERT] = COMBO(y_u_insert, KC_INSERT),
  [U_I_DELETE] = COMBO(u_i_delete, KC_DELETE),
  [I_O_BSPC] = COMBO(i_o_bspc, KC_BSPC),
  [K_L_ENTER] = COMBO(k_l_enter, KC_ENTER),
  [Y_N_PSCR] = COMBO(y_n_pscr, KC_PSCR),

  [Y_H_NAV_LAYER] = COMBO(y_h_nav_layer, TG(NAV)),
  [H_N_MOS_LAYER] = COMBO(h_n_mos_layer, TG(MOS)),
  [P_TILD_KPD_LAYER] = COMBO(p_tild_kpd_layer, TG(KPD)),
  [TILD_SCLN_MED_LAYER] = COMBO(tild_scln_med_layer, TG(MED)),


  [G_H_CAPSWORD] = COMBO(g_h_capsword, CW_TOGG),
  [B_N_PAUSE] = COMBO(b_n_pause, KC_PAUSE)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BAS] = LAYOUT_split_3x5_2(
        KC_Q, KC_W, KC_E, KC_R, KC_T,    KC_Y, KC_U, KC_I,     KC_O,   KC_P,
        KC_A, KC_S, KC_D, KC_F, KC_G,    KC_H, KC_J, KC_K,     KC_L,   BR_TILD,
        KC_Z, KC_X, KC_C, KC_V, KC_B,    KC_N, KC_M, KC_COMMA, KC_DOT, BR_SCLN,
        TD(OSL_SYM_LCTL), LSFT_T(KC_SPC), TD(OSL_NUM_LGUI), TD(OSL_COMPOSE_LALT)
    ),
    [NUM] = LAYOUT_split_3x5_2(
        KC_1,  KC_2,  KC_3,  KC_4,  KC_5,     KC_6,    KC_7,     KC_8,     KC_9,   KC_0,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    BR_LBRC, KC_MINUS, KC_EQUAL, BR_GRV, BR_QUOT,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    BR_RBRC, BR_BSLS,  KC_COMMA, KC_DOT, BR_SLSH,
        OSM(MOD_LCTL), KC_TRNS,               OSM(MOD_LGUI), OSM(MOD_LALT)
    ),
    [KPD] = LAYOUT_split_3x5_2(
        KC_NO, KC_NO, KC_KP_SLASH, KC_KP_ASTERISK, KC_NO,    KC_0,     KC_1, KC_2, KC_3, KC_NO,
        KC_NO, KC_NO, KC_KP_MINUS, KC_KP_PLUS,     KC_NO,    KC_DOT,   KC_4, KC_5, KC_6, KC_NO,
        KC_NO, KC_NO, KC_PERCENT,  KC_KP_EQUAL,    KC_NO,    KC_COMMA, KC_7, KC_8, KC_9, KC_NO,
        OSM(MOD_LCTL), KC_TRNS,                              OSM(MOD_LGUI), OSM(MOD_LALT)
    ),
    [SYM] = LAYOUT_split_3x5_2(
        LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),    LSFT(KC_6),    LSFT(KC_7),     LSFT(KC_8),     LSFT(KC_9),   LSFT(KC_0),
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,         LSFT(BR_LBRC), LSFT(KC_MINUS), LSFT(KC_EQUAL), BR_GRV,       LSFT(BR_QUOT),
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,         LSFT(BR_RBRC), LSFT(BR_BSLS),  LSFT(KC_COMMA), LSFT(KC_DOT), LSFT(BR_SLSH),
        OSM(MOD_LCTL), KC_TRNS,                                        OSM(MOD_LGUI), OSM(MOD_LALT)
    ),
    [NAV] = LAYOUT_split_3x5_2(
        KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_NO,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,
        KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS
    ),
    [MOS] = LAYOUT_split_3x5_2(
        KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_NO,    KC_WH_L,    KC_WH_D,    KC_WH_U,    KC_WH_R, KC_MS_ACCEL0,
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_MS_L,    KC_MS_D,    KC_MS_U,    KC_MS_R, KC_MS_ACCEL1,
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_MS_BTN3, KC_MS_BTN4, KC_MS_BTN5, KC_NO,   KC_MS_ACCEL2,
        KC_TRNS, KC_TRNS,                           KC_MS_BTN1, KC_MS_BTN2
    ),
    [MED] = LAYOUT_split_3x5_2(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO,   KC_BRID, KC_BRIU, KC_NO,   KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_MUTE, KC_VOLD, KC_VOLU, KC_NO,   KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, KC_NO,
        KC_NO, KC_NO,                         KC_NO, KC_NO
    ),
    [FNC] = LAYOUT_split_3x5_2(
        KC_NO, KC_F3, KC_F2, KC_F1, KC_F10,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_F6, KC_F5, KC_F4, KC_F11,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_F9, KC_F8, KC_F7, KC_F12,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        OSM(MOD_LCTL), KC_TRNS,                OSM(MOD_LGUI), OSM(MOD_LALT)
    ),
    [SYS] = LAYOUT_split_3x5_2(
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

// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_macros.md#super-alttab
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
  }
  return true;
}

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}
