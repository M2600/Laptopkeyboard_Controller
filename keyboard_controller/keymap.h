#include <HID-Project.h>
#include <HID-Settings.h>

// japanese keyboard
#define KEY_JP_COLON KEY_NON_US
#define KEY_JP_AT KEY_NON_US
#define KEY_JP_CARET KEY_NON_US

#define KEY_JP_HANZEN KEY_TILDE
#define KEY_JP_KANJI KEY_TILDE // Alias
#define KEY_JP_BACKSLASH KEY_INTERNATIONAL1
#define KEY_JP_HIRAGANA KEY_INTERNATIONAL2
#define KEY_JP_YEN KEY_INTERNATIONAL3
#define KEY_JP_HENKAN KEY_INTERNATIONAL4
#define KEY_JP_MUHENKAN KEY_INTERNATIONAL5

KeyboardKeycode KEY_FN = 0xff;
KeyboardKeycode _  = 0x00;

KeyboardKeycode keymap[8][15] = {
    {KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_LEFT_ALT,  KEY_LEFT_CTRL,  KEY_LEFT_SHIFT,  KEY_JP_BACKSLASH, KEY_SPACE,        KEY_N,   KEY_B,    KEY_JP_YEN, _,      KEY_C,  KEY_X,   KEY_JP_MUHENKAN, KEY_LEFT_GUI},
    {KEY_UP_ARROW,    KEY_LEFT_ARROW, KEY_RIGHT_ALT, KEY_RIGHT_CTRL, KEY_RIGHT_SHIFT, KEY_PERIOD,       KEY_COMMA,        KEY_J,   KEY_H,    KEY_V,      KEY_F,  _,      KEY_Z,   _,               _           },
    {_,               KEY_JP_HENKAN,  _,             _,              _,               KEY_SLASH,        KEY_M,            KEY_K,   KEY_I,    KEY_G,      KEY_D,  KEY_S,  KEY_A,   KEY_APPLICATION, _           },
    {KEY_JP_HIRAGANA, KEY_ENTER,      _,             _,              _,               KEY_SEMICOLON,    KEY_RIGHT_BRACE,  KEY_O,   KEY_U,    KEY_Y,      KEY_R,  KEY_W,  KEY_Q,   KEY_FN,          _           },
    {_,               KEY_JP_COLON,   _,             _,              _,               KEY_JP_AT,        KEY_L,            KEY_9,   KEY_7,    KEY_T,      KEY_E,  KEY_4,  KEY_2,   KEY_CAPS_LOCK,   _           },
    {_,               KEY_LEFT_BRACE, _,             _,              _,               KEY_JP_CARET,     KEY_P,            KEY_0,   KEY_8,    KEY_6,      KEY_5,  KEY_3,  KEY_1,   KEY_TAB,         _           },
    {_,               KEY_BACKSPACE,  _,             _,              _,               KEY_PRINTSCREEN,  KEY_MINUS,        KEY_F12, KEY_F10,  KEY_F8,     KEY_F6, KEY_F4, KEY_F2,  KEY_JP_HANZEN,   _           },
    {_,               KEY_DELETE,     _,             _,              _,               KEY_INSERT,       KEY_PAUSE,        KEY_F11, KEY_F9,   KEY_F7,     KEY_F5, KEY_F3, KEY_F1,  KEY_ESC,         _           }
};