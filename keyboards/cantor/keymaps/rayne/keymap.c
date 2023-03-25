#include QMK_KEYBOARD_H

//Tap Dance Declarations
enum {
  TD_ESC_CAPS = 0
};

//Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)
// Other declarations would go here, separated by commas, if you have them
};

//In Layer declaration, add tap dance item in place of a key code
//TD(TD_ESC_CAPS)

/*
 * ┌────────┬────────┬────────┬────────┬────────┬────────┐    ┌────────┬────────┬────────┬────────┬────────┬────────┐
 * │  Tab   │   Q    │   W    │   E    │   R    │   T    │    │   Y    │   U    │   I    │   O    │   P    │ Bksp   │
 * ├────────┼────────┼────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┼────────┤
 * │  Esc   │   A    │   S    │   D    │   F    │   G    │    │   H    │   J    │   K    │   L    │   ;    │   '    │
 * ├────────┼────────┼────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┼────────┤
 * │ Shift  │   Z    │   X    │   C    │   V    │   B    │    │   N    │   M    │   ,    │   .    │   /    │ Shift  │
 * └────────┴────────┴────────┴────────┴────────┴────────┘    └────────┴────────┴────────┴────────┴────────┴────────┘
 *                            ┌────────┐                                        ┌────────┐
 *                            │  LCTL  ├────────┐                      ┌────────┤ Alt    │
 *                            └────────┤GUI/Bsp ├────────┐    ┌────────┤ TO(1)  ├────────┘
 *                                     └────────┤ALT/ENT │    │  SPC   ├────────┘
 *                                              └────────┘    └────────┘
 */

#define R_LCTL  MT(MOD_LCTL, KC_ESC)

#define R_LBSPC MT(MOD_LALT, KC_BSPC)
#define R_LDEL  MT(MOD_LGUI, KC_DEL)
#define R_L3    LT(1, KC_ESC)

#define R_RENT  MT(MOD_LALT, KC_ENT)
#define R_RSPC  MT(MOD_LALT, KC_SPC)
#define R_R3    LT(2, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * ┌────────┬────────┬────────┬────────┬────────┬────────┐    ┌────────┬────────┬────────┬────────┬────────┬────────┐
 * │  Tab   │   Q    │   W    │   E    │   R    │   T    │    │   Y    │   U    │   I    │   O    │   P    │ Bksp   │
 * ├────────┼────────┼────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┼────────┤
 * │  Esc   │   A    │   S    │   D    │   F    │   G    │    │   H    │   J    │   K    │   L    │   ;    │   '    │
 * ├────────┼────────┼────────┼────────┼────────┼────────┤    ├────────┼────────┼────────┼────────┼────────┼────────┤
 * │ Shift  │   Z    │   X    │   C    │   V    │   B    │    │   N    │   M    │   ,    │   .    │   /    │ Shift  │
 * └────────┴────────┴────────┴────────┴────────┴────────┘    └────────┴────────┴────────┴────────┴────────┴────────┘
 *                            ┌────────┐                                        ┌────────┐
 *                            │Alt/Bksp├────────┐                      ┌────────┤ Alt    │
 *                            └────────┤GUI/Del ├────────┐    ┌────────┤ TO(1)  ├────────┘
 *                                     └────────┤ALT/ENT │    │  SPC   ├────────┘
 *                                              └────────┘    └────────┘
 */
    [0] = LAYOUT_split_3x6_3(
        KC_TAB,     KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
        R_LCTL,     KC_A,    KC_R,    KC_S,    KC_T,    KC_G,       KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,       KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                         R_L3, R_LBSPC, R_LDEL,   R_RENT, R_RSPC, R_R3
    ),
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │`~ │ 1 │ 2 │ 3 │ 4 │ 5 │       │ 6 │ 7 │ 8 │ 9 │ 0 │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ ! │ @ │ # │ $ │ % │       │ ^ │ & │ * │ ( │ ) │ | │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ +=│ -_│ + │ { │ } │       │ [ │ ] │ ; │ : │ \ │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *           ┌────────┐                       ┌─────┐
      *           │ MLCKSCN├─────┐           ┌─────┤TO(3)│
      *           └────────┤TO(0)├───┐   ┌───┤TO(2)├─────┘
      *                    └─────┤ < │   │ > ├─────┘
      *                          └───┘   └───┘
      */
    [1] = LAYOUT_split_3x6_3(
        KC_GRV,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TRNS,    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
        KC_LSFT,    KC_EQL,  KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR,    KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, KC_RSFT,
                                          KC_TRNS, TO(0), KC_LT,  KC_GT, TO(2), TO(3)
    ),
     /*
      * ┌────┬──────┬──────┬──────┬──────────┬──────┐       ┌──────┬──────┬──────┬───────┬──────┬───┐
      * │MSTP│ Play │ PRVS │ Next   │          │ CAPS  │       │ PgDn │ PgUp  │ INS   │ Print │      │Bsp│
      * ├────┼──────┼──────┼───────┼─────────┼──────┤       ├──────┼──────┼──────┼───────┼──────┼───┤
      * │    │ HOME │ END  │ LCTRL+C │ LCTRL+V │      │       │ Left │ Down │ Up │ Right │ Del  │   │
      * ├────┼──────┼──────┼───────┼────────┼──────┤       ├──────┼──────┼──────┼───────┼──────┼───┤
      * │Sft │ UNDO │ CUT  │ COPY │ PASTE │ RApp │       │ Vol- │ Vol+ │ Mute │       │ RGui │   │
      * └────┴──────┴──────┴──────┴───────┴──────┘       └──────┴──────┴──────┴───────┴──────┴───┘
      *                                ┌─────┐                       ┌─────┐
      *                                │LCTRL├─────┐           ┌─────┤TO(3)│
      *                                └─────┤TO(0)├───┐   ┌───┤TO(0)├─────┘
      *                                      └─────┤ALT│   │SPC├─────┘
      *                                            └───┘   └───┘
      */
    [2] = LAYOUT_split_3x6_3(
        KC_MSTP,    KC_MPLY, KC_MPRV, KC_MNXT, QK_BOOT, KC_CAPS,    KC_PGDN, KC_PGUP, KC_INS,  KC_PSCR, KC_NO,   KC_BSPC,
        KC_NO,      KC_HOME, KC_END,  C(KC_C), C(KC_V), KC_NO,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,  KC_NO,
        KC_TAB,     KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE,KC_APP,     KC_VOLD, KC_VOLU, KC_MUTE, KC_NO,   KC_NO,   KC_RSFT,
                                        KC_LCTL, TO(0), KC_LALT,  KC_TRNS, KC_TRNS, TO(3)
    ),
     /*
      * ┌──┬────┬────┬────┬────┬────┐       ┌────┬────┬────┬────┬─────┬─────┐
      * │  │ F1 │ F2   │ F3 │ F4 │ F5 │       │ F6 │ F7 │ F8 │ F9  │ F10 │ F11 │
      * ├──┼────┼────┼────┼────┼────┤       ├────┼────┼────┼────┼─────┼─────┤
      * │  │    │     │    │    │     │       │    │    │    │    │      │ F12 │
      * ├──┼────┼────┼────┼────┼────┤       ├────┼────┼────┼────┼─────┼─────┤
      * │  │    │     │    │    │    │       │     │    │    │    │      │     │
      * └──┴────┴────┴────┴────┴────┘       └────┴────┴────┴────┴─────┴─────┘
      *                   ┌───┐                        ┌───┐
      *                   │   ├─────┐           ┌─────┤   │
      *                   └───┤TO(0)├───┐   ┌───┤     ├───┘
      *                       └─────┤ENT│   │   ├─────┘
      *                             └───┘   └───┘
      */
    [3] = LAYOUT_split_3x6_3(
        KC_NO,      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_NO,      KC_ASTR, KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_ASTR, KC_F12,
        QK_RBT,     QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT, QK_RBT,
                                            KC_NO, TO(0), KC_NO,  KC_NO, KC_NO, KC_NO
    ),
    [4] = LAYOUT_split_3x6_3(
        KC_TAB,     KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
        R_LCTL,     KC_A,    KC_R,    KC_S,    KC_T,    KC_G,       KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,       KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                         R_L3, R_LBSPC, R_LDEL,   R_RENT, R_RSPC, R_R3
    ),
};
