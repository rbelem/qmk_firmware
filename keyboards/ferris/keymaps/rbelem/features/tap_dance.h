#pragma once

#include "quantum.h"
#include "keymap.h"

// Keep track of key presses for Modifier
typedef struct {
  bool is_press_action;
  int state;
} tap;

// Key Tap enumerator
enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  TRIPLE_TAP = 5,
  TRIPLE_HOLD = 6
};

//Tap Dance Declarations
enum {
    OSL_SYM_LCTL,
    OSL_NUM_LGUI,
    OSL_COMPOSE_LALT,
};

// Alt key action:
// SINGLE_TAP = toggle layer, then wait for keypress on called layer, then switch back to original layer.
// SINGLE_HOLD = will work as normal sending the keypress.
// DOUBLE_TAP = 3,
// DOUBLE_HOLD = will then toggle layer and keep sending the Alt keycode until next keypress, then switch back to original layer.
// TRIPLE_TAP = 5,
// TRIPLE_HOLD = 6
// // Alt held down, then use as normal.
//
// Alt tapped, then hold Alt,
int tap_dance_state (tap_dance_state_t *state);

void osl_sym_lctl_finished (tap_dance_state_t *state, void *user_data);
void osl_sym_lctl_reset (tap_dance_state_t *state, void *user_data);

void osl_num_lgui_finished (tap_dance_state_t *state, void *user_data);
void osl_num_lgui_reset (tap_dance_state_t *state, void *user_data);

void osl_compose_lalt_finished (tap_dance_state_t *state, void *user_data);
void osl_compose_lalt_reset (tap_dance_state_t *state, void *user_data);
