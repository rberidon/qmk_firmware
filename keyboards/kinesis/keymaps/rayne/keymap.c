#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum kinesis_layers {
  _QWERTY,    // QWERTY
  _COLEMAK,   // Colemak (default layer)
  _GAMING,    // Gaming/vanilla toggle layer (limited dual-role keys and layer access)
  _NUMBERS,   // Numbers & Symbols
  _FUNCTION,  // Function
  _NUMPAD,    // Numpad
  _ADJUST,    // Adjust layer (accessed via tri-layer feature)

  _M_BASE_COLEMAK,    // Miryoku Base
  _M_NAV,     // Miryoku Nav
  _M_MEDIA,   // Miryoku Media
  _M_NUM,     // Miryoku Numbers
  _M_SYM,     // Miryoku Symbols
  _M_FUN      // Miryoku Function
};

#define L_CMK DF(_COLEMAK)
#define L_QWE DF(_QWERTY)
#define L_MIR DF(_M_BASE_COLEMAK)
#define L_GAM TG(_GAMING)

//Tap Dance Declarations
enum {
  LBCB = 0,
  RBCB,
  EQPL,
  PLEQ,
  MNUN,
  SLAS,
  GVTL,
  PPEQ,
  PMUN,
  PSPA
};

qk_tap_dance_action_t tap_dance_actions[] = {
[LBCB] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),  // Left bracket on a single-tap, left brace on a double-tap
[RBCB] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),  // Right bracket on a single-tap, right brace on a double-tap
[EQPL] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_PLUS),   // Plus sign on a single-tap, equal sign on a double-tap
[PLEQ] = ACTION_TAP_DANCE_DOUBLE(KC_PLUS, KC_EQL),   // Equal sign on a single-tap, plus sign on a double-tap
[MNUN] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_UNDS),  // Minus sign on a single-tap, underscore on a double-tap
[SLAS] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_ASTR),  // Slash in a single-tap, asterisk in a double-tap
[GVTL] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_TILD),   // Grave on a single-tap, tilde on a double-tap
[PPEQ] = ACTION_TAP_DANCE_DOUBLE(KC_PPLS, KC_EQL),   // Numpad plus sign on a single-tap, equal sign on a double-tap
[PMUN] = ACTION_TAP_DANCE_DOUBLE(KC_PMNS, KC_UNDS),  // Numpad minus sign on a single-tap, underscore on a double-tap
[PSPA] = ACTION_TAP_DANCE_DOUBLE(KC_PSLS, KC_PAST)   // Numpad slash on a single-tap, numpad asterisk on a double-tap
};

//Aliases for longer keycodes
#define NUMPAD  TG(_NUMPAD)
#define ADJUST  MO(_ADJUST)
#define SPCFN   LT(_FUNCTION, KC_SPC)
#define ENTNS   LT(_NUMBERS, KC_ENT)
#define CTLESC  CTL_T(KC_ESC)
#define ALTAPP  ALT_T(KC_APP)
#define CTL_A   LCTL(KC_A)
#define CTL_C   LCTL(KC_C)
#define CTL_V   LCTL(KC_V)
#define CTL_X   LCTL(KC_X)
#define CTL_Z   LCTL(KC_Z)
#define CTL_Y   LCTL(KC_Y)
#define CA_TAB  LCA(KC_TAB)
#define HYPER   ALL_T(KC_NO)
#define TD_LBCB TD(LBCB)
#define TD_RBCB TD(RBCB)
#define TD_EQPL TD(EQPL)
#define TD_PLEQ TD(PLEQ)
#define TD_MNUN TD(MNUN)
#define TD_SLAS TD(SLAS)
#define TD_GVTL TD(GVTL)
#define TD_PPEQ TD(PPEQ)
#define TD_PMUN TD(PMUN)
#define TD_PSPA TD(PSPA)
#define NKROTG  MAGIC_TOGGLE_NKRO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = LAYOUT_pretty(
  KC_ESC,  L_CMK,   L_QWE,   L_MIR,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, RESET, NUMPAD,  ADJUST,
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                                          KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
  CTLESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                                          KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                                                          KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
           KC_GRV,  KC_EQL,  KC_LEFT, KC_RGHT,                                                                         KC_DOWN, KC_UP,   KC_LBRC, KC_RBRC,
                                                        KC_LALT, KC_LGUI,                   KC_RGUI, KC_RALT,
                                                                 KC_HOME,                   KC_PGUP,
                                                 KC_BSPC, KC_DEL, KC_END,                   KC_PGDN,  ENTNS, SPCFN
),

[_QWERTY] = LAYOUT_pretty(
  KC_ESC,  L_CMK,   L_QWE,   L_MIR,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, RESET,   NUMPAD,  ADJUST,
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  CTLESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                                          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                                          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
           KC_GRV,  KC_EQL,  KC_LEFT, KC_RGHT,                                                                         KC_DOWN, KC_UP,   KC_LBRC, KC_RBRC,
                                                        KC_LALT, KC_LGUI,                   KC_RGUI, KC_RALT,
                                                                 KC_HOME,                   KC_PGUP,
                                                 KC_BSPC, KC_DEL, KC_END,                    KC_PGDN,  ENTNS, SPCFN
),

[_NUMBERS] = LAYOUT_pretty(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                                         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                                                          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                                          KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,
  _______, _______, KC_DOT,  TD_SLAS, TD_MNUN, TD_PLEQ,                                                       TD_GVTL, TD_LBCB, TD_RBCB, _______, _______, _______,
           KC_LPRN, KC_RPRN, TD_LBCB, TD_RBCB,                                                                         _______, _______, _______, _______,
                                                        _______, _______,                   _______, _______,
                                                                 _______,                   _______,
                                               _______, _______, _______,                   _______, _______, _______
),

[_FUNCTION] = LAYOUT_pretty(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                                         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, _______, _______, KC_UP,   _______, _______,                                                       _______, _______, KC_UP,   CTL_Y,   _______, _______,
  _______, CTL_A,   KC_LEFT, KC_DOWN, KC_RGHT, CA_TAB,                                                        KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, KC_HOME, _______,
  _______, CTL_Z,   CTL_X,   CTL_C,   CTL_V,   KC_BSPC,                                                       KC_PGDN, KC_MUTE, KC_VOLD, KC_VOLU, KC_END,  _______,
           _______, _______, _______, _______,                                                                         KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP,
                                                        _______, _______,                   _______, _______,
                                                                 _______,                   _______,
                                               _______, _______, _______,                   _______, _______, _______
),

[_NUMPAD] = LAYOUT_pretty(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_NLCK, _______, _______, _______, _______,                                                       KC_TAB,  KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, _______,
  _______, KC_P6,   KC_P7,   KC_P8,   KC_P9,   KC_P0,                                                         _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______,
  _______, KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_P5,                                                         _______, KC_P4,   KC_P5,   KC_P6,   KC_EQL,  _______,
  _______, _______, KC_PDOT, TD_PSPA, TD_MNUN, TD_PPEQ,                                                       _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______,
           KC_LPRN, KC_RPRN, TD_LBCB, TD_RBCB,                                                                         _______, KC_P0,   KC_PDOT, KC_PENT,
                                                        _______, _______,                   _______, _______,
                                                                 _______,                   _______,
                                               _______, _______, _______,                   _______, _______, _______
),

[_GAMING] = LAYOUT_pretty(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______, _______,
  KC_LCTL, _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______, _______,
  KC_LSFT, _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______, KC_RSFT,
           _______, _______, _______, _______,                                                                         _______, _______, _______, _______,
                                                        KC_ESC,  XXXXXXX,                   _______, _______,
                                                                 KC_LALT,                   _______,
                                               KC_SPC,  KC_ENT,  _______,                   ENTNS,   _______, _______
),

[_ADJUST] = LAYOUT_pretty(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, L_CMK,   L_QWE,   _______, L_GAM,   _______,                                                       NUMPAD,  _______, _______, _______, _______, RESET,
  _______, _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______, _______,
  _______, DT_PRNT, DT_DOWN,   DT_UP, _______, _______,                                                       _______, NKROTG,  _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______,                                                                         _______, _______, _______, _______,
                                                        _______, _______,                   _______, _______,
                                                                 _______,                   _______,
                                               _______, _______, _______,                   _______, _______, _______
),

/*
Using KC_NO on keys that Miryoku keyboards wouldn't have.

Default mods:
          LT(_M_MEDIA, KC_ESC), LT(_M_NAV, KC_SPC), LT(_M_MOUSE, KC_TAB),                   LT(_M_SYM, KC_ENT), LT(_M_NUM, KC_BSPC), LT(_M_FUN, KC_DEL)
*/
[_M_BASE_COLEMAK] = LAYOUT_pretty(
    KC_ESC,  L_CMK,   L_QWE,   L_MIR,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, RESET,   NUMPAD,  ADJUST,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                                       KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_NO,
    KC_NO, LCTL_T(KC_A), LALT_T(KC_R), LGUI_T(KC_S), LSFT_T(KC_T), KC_G,                     KC_M, RSFT_T(KC_N), RGUI_T(KC_E), RALT_T(KC_I), RCTL_T(KC_O), KC_NO,
    KC_NO,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                                                       KC_K, KC_H, KC_COMM, RALT_T(KC_DOT),KC_SLSH, KC_NO,
             KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                                         KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                                          KC_NO,   KC_NO,                   KC_NO,   KC_NO,
                                                                   KC_NO,                   KC_NO,
         LT(_M_MEDIA, KC_BSPC), LT(_M_NAV, KC_DEL), KC_TAB,                   LT(_M_SYM, KC_ESC), LT(_M_NUM, KC_ENT), LT(_M_FUN, KC_SPC)
),

/*
[_M_BASE_QWERTY] = LAYOUT_pretty(
    KC_ESC,  L_CMK,   L_QWE,   L_MIR,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, RESET,   NUMPAD,  ADJUST,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
    KC_NO, LSFT_T(KC_A), LCTL_T(KC_S), LALT_T(KC_D), LGUI_T(KC_F), KC_G,                                      KC_H,    LGUI_T(KC_J),  LALT_T(KC_K), LALT_T(KC_L), LSFT_T(KC_SCLN), KC_NO,
    KC_NO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                                       KC_N, KC_M, KC_COMM, RALT_T(KC_DOT),KC_SLSH, KC_NO,
             KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                                         KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                                          KC_NO,   KC_NO,                   KC_NO,   KC_NO,
                                                                   KC_NO,                   KC_NO,
         LT(_M_MEDIA, KC_BSPC), LT(_M_NAV, KC_DEL), LT(_M_MOUSE, KC_TAB),                   LT(_M_SYM, KC_ESC), LT(_M_NUM, KC_ENT), LT(_M_FUN, KC_SPC)
),
*/

// TODO: Decide on which mod layout I like better
// TODO: KC_AGIN, KC_UNDO, KC_CUT, KC_COPY, KC_PSTE,
[_M_NAV] = LAYOUT_pretty(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______, _______,
  _______,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,
  _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT,   KC_NO,                                                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS, _______,
  _______,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                       KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  _______,
           _______, _______, _______, _______,                                                                         _______, _______, _______, _______,
                                                        _______, _______,                   _______, _______,
                                                                 _______,                   _______,
                                                 KC_NO,   KC_NO,   KC_NO,                   KC_ENT, KC_BSPC, KC_DEL
),

[_M_MEDIA] = LAYOUT_pretty(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______, _______,
  _______,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                       KC_NO,   KC_NO,   KC_NO,   _______,   KC_NO,   _______,
  _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,   KC_NO,                                                       KC_NO,   KC_VOLD, KC_VOLU, KC_MUTE, KC_NO,   _______,
  _______,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                       KC_NO,   KC_MNXT, KC_MPRV, KC_MSTP, KC_NO,   _______,
           _______, _______, _______, _______,                                                                         _______, _______, _______, _______,
                                                        _______, _______,                   _______, _______,
                                                                 _______,                   _______,
                                                 KC_NO,   KC_NO,   KC_NO,                   KC_NO,   KC_MPLY, KC_NO
),

[_M_NUM] = LAYOUT_pretty(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______, _______,
  _______, KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,                                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,
  _______, KC_SCLN,    KC_4,    KC_5,    KC_6,  KC_EQL,                                                       KC_NO,   KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, _______,
  _______,  KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS,                                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,
           _______, _______, _______, _______,                                                                         _______, _______, _______, _______,
                                                        _______, _______,                   _______, _______,
                                                                 _______,                   _______,
                                                KC_DOT,    KC_0, KC_MINS,                   KC_NO,   KC_NO,   KC_NO
),

[_M_SYM] = LAYOUT_pretty(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______, _______,
  _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,
  _______, KC_COLN,  KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,                                                       KC_NO,   KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, _______,
  _______, KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE,                                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
           _______, _______, _______, _______,                                                                         _______, _______, _______, _______,
                                                        _______, _______,                   _______, _______,
                                                                 _______,                   _______,
                                               KC_LPRN, KC_RPRN, KC_UNDS,                   KC_NO,   KC_NO,   KC_NO
),

[_M_FUN] = LAYOUT_pretty(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______, _______,
  _______,  KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_PSCR,                                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,
  _______,  KC_F11,   KC_F4,   KC_F5,   KC_F6, KC_SLCK,                                                       KC_NO,   KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, _______,
  _______,  KC_F10,   KC_F1,   KC_F2,   KC_F3, KC_PAUS,                                                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______,
           _______, _______, _______, _______,                                                                         _______, _______, _______, _______,
                                                        _______, _______,                   _______, _______,
                                                                 _______,                   _______,
                                                  KC_APP, KC_SPC, KC_TAB,                   KC_NO,   KC_NO,   KC_NO
)

};
