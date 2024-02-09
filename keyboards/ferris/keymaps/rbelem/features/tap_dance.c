
#include "tap_dance.h"


//Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
    [OSL_SYM_LCTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, osl_sym_lctl_finished, osl_sym_lctl_reset),
    [OSL_NUM_LGUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, osl_num_lgui_finished, osl_num_lgui_reset),
    [OSL_COMPOSE_LALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, osl_compose_lalt_finished, osl_compose_lalt_reset),
};


int tap_dance_state (tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->pressed) return SINGLE_HOLD;
    else return SINGLE_TAP;
  }
  else if (state->count == 2) {
    if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  else if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 8;
}

static tap osl_sym_lctl_tap_state = {
  .is_press_action = true,
  .state = 0
};

void osl_sym_lctl_finished (tap_dance_state_t *state, void *user_data) {
  osl_sym_lctl_tap_state.state = tap_dance_state(state);
  switch (osl_sym_lctl_tap_state.state) {
    case SINGLE_TAP:
        set_oneshot_layer(SYM, ONESHOT_START);
        clear_oneshot_layer_state(ONESHOT_PRESSED);
        break;
    case SINGLE_HOLD:
        register_code(KC_LCTL);
        break;
    case DOUBLE_TAP:
        register_code(KC_RCTL);
        break;
    case DOUBLE_HOLD:
        register_code(KC_LCTL);
        layer_on(SYM);
        break;
  }
}

void osl_sym_lctl_reset (tap_dance_state_t *state, void *user_data) {
  switch (osl_sym_lctl_tap_state.state) {
    case SINGLE_TAP: break;
    case SINGLE_HOLD: unregister_code(KC_LCTL); break;
    case DOUBLE_TAP: unregister_code(KC_RCTL); break;
    case DOUBLE_HOLD: layer_off(SYM); unregister_code(KC_LCTL); break;
  }
  osl_sym_lctl_tap_state.state = 0;
}


static tap osl_num_lgui_tap_state = {
  .is_press_action = true,
  .state = 0
};

void osl_num_lgui_finished (tap_dance_state_t *state, void *user_data) {
  osl_num_lgui_tap_state.state = tap_dance_state(state);
  switch (osl_num_lgui_tap_state.state) {
    case SINGLE_TAP:
        set_oneshot_layer(NUM, ONESHOT_START);
        clear_oneshot_layer_state(ONESHOT_PRESSED);
        break;
    case SINGLE_HOLD:
        register_code(KC_LGUI);
        break;
  }
}

void osl_num_lgui_reset (tap_dance_state_t *state, void *user_data) {
  switch (osl_num_lgui_tap_state.state) {
    case SINGLE_TAP: break;
    case SINGLE_HOLD: unregister_code(KC_LGUI); break;
  }
  osl_num_lgui_tap_state.state = 0;
}


static tap osl_compose_lalt_tap_state = {
  .is_press_action = true,
  .state = 0
};

void osl_compose_lalt_finished (tap_dance_state_t *state, void *user_data) {
  osl_compose_lalt_tap_state.state = tap_dance_state(state);
  switch (osl_compose_lalt_tap_state.state) {
    case SINGLE_TAP:
        register_code16(LSFT(KC_RALT));
        break;
    case SINGLE_HOLD:
        register_code(KC_LALT);
        break;
    case DOUBLE_TAP:
    case DOUBLE_HOLD:
        register_code(KC_RALT);
        break;
  }
}

void osl_compose_lalt_reset (tap_dance_state_t *state, void *user_data) {
  switch (osl_compose_lalt_tap_state.state) {
    case SINGLE_TAP:
        unregister_code16(LSFT(KC_RALT));
        break;
    case SINGLE_HOLD:
        unregister_code(KC_LALT);
        break;
    case DOUBLE_TAP:
    case DOUBLE_HOLD:
        unregister_code(KC_RALT);
        break;
  }
  osl_compose_lalt_tap_state.state = 0;
}
