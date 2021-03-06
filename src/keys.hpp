#ifndef KEYS_HPP
#define KEYS_HPP

#include <unordered_map>

#include <dinput.h>

#include "types.hpp"

const std::unordered_map<std::string, Key> keys {
    {"ESCAPE", DIK_ESCAPE},
    {"1", DIK_1},
    {"2", DIK_2},
    {"3", DIK_3},
    {"4", DIK_4},
    {"5", DIK_5},
    {"6", DIK_6},
    {"7", DIK_7},
    {"8", DIK_8},
    {"9", DIK_9},
    {"0", DIK_0},
    {"MINUS", DIK_MINUS},
    {"EQUALS", DIK_EQUALS},
    {"BACK", DIK_BACK},
    {"TAB", DIK_TAB},
    {"Q", DIK_Q},
    {"W", DIK_W},
    {"E", DIK_E},
    {"R", DIK_R},
    {"T", DIK_T},
    {"Y", DIK_Y},
    {"U", DIK_U},
    {"I", DIK_I},
    {"O", DIK_O},
    {"P", DIK_P},
    {"LBRACKET", DIK_LBRACKET},
    {"RBRACKET", DIK_RBRACKET},
    {"RETURN", DIK_RETURN},
    {"LCONTROL", DIK_LCONTROL},
    {"A", DIK_A},
    {"S", DIK_S},
    {"D", DIK_D},
    {"F", DIK_F},
    {"G", DIK_G},
    {"H", DIK_H},
    {"J", DIK_J},
    {"K", DIK_K},
    {"L", DIK_L},
    {"SEMICOLON", DIK_SEMICOLON},
    {"APOSTROPHE", DIK_APOSTROPHE},
    {"GRAVE", DIK_GRAVE},
    {"LSHIFT", DIK_LSHIFT},
    {"BACKSLASH", DIK_BACKSLASH},
    {"Z", DIK_Z},
    {"X", DIK_X},
    {"C", DIK_C},
    {"V", DIK_V},
    {"B", DIK_B},
    {"N", DIK_N},
    {"M", DIK_M},
    {"COMMA", DIK_COMMA},
    {"PERIOD", DIK_PERIOD},
    {"SLASH", DIK_SLASH},
    {"RSHIFT", DIK_RSHIFT},
    {"MULTIPLY", DIK_MULTIPLY},
    {"LMENU", DIK_LMENU},
    {"SPACE", DIK_SPACE},
    {"CAPITAL", DIK_CAPITAL},
    {"F1", DIK_F1},
    {"F2", DIK_F2},
    {"F3", DIK_F3},
    {"F4", DIK_F4},
    {"F5", DIK_F5},
    {"F6", DIK_F6},
    {"F7", DIK_F7},
    {"F8", DIK_F8},
    {"F9", DIK_F9},
    {"F10", DIK_F10},
    {"NUMLOCK", DIK_NUMLOCK},
    {"SCROLL", DIK_SCROLL},
    {"NUMPAD7", DIK_NUMPAD7},
    {"NUMPAD8", DIK_NUMPAD8},
    {"NUMPAD9", DIK_NUMPAD9},
    {"SUBTRACT", DIK_SUBTRACT},
    {"NUMPAD4", DIK_NUMPAD4},
    {"NUMPAD5", DIK_NUMPAD5},
    {"NUMPAD6", DIK_NUMPAD6},
    {"ADD", DIK_ADD},
    {"NUMPAD1", DIK_NUMPAD1},
    {"NUMPAD2", DIK_NUMPAD2},
    {"NUMPAD3", DIK_NUMPAD3},
    {"NUMPAD0", DIK_NUMPAD0},
    {"DECIMAL", DIK_DECIMAL},
    {"OEM_102", DIK_OEM_102},
    {"F11", DIK_F11},
    {"F12", DIK_F12},
    {"F13", DIK_F13},
    {"F14", DIK_F14},
    {"F15", DIK_F15},
    {"KANA", DIK_KANA},
    {"ABNT_C1", DIK_ABNT_C1},
    {"CONVERT", DIK_CONVERT},
    {"NOCONVERT", DIK_NOCONVERT},
    {"YEN", DIK_YEN},
    {"ABNT_C2", DIK_ABNT_C2},
    {"NUMPADEQUALS", DIK_NUMPADEQUALS},
    {"CIRCUMFLEX", DIK_CIRCUMFLEX},
    {"AT", DIK_AT},
    {"COLON", DIK_COLON},
    {"UNDERLINE", DIK_UNDERLINE},
    {"KANJI", DIK_KANJI},
    {"STOP", DIK_STOP},
    {"AX", DIK_AX},
    {"UNLABELED", DIK_UNLABELED},
    {"NEXTTRACK", DIK_NEXTTRACK},
    {"NUMPADENTER", DIK_NUMPADENTER},
    {"RCONTROL", DIK_RCONTROL},
    {"MUTE", DIK_MUTE},
    {"CALCULATOR", DIK_CALCULATOR},
    {"PLAYPAUSE", DIK_PLAYPAUSE},
    {"MEDIASTOP", DIK_MEDIASTOP},
    {"VOLUMEDOWN", DIK_VOLUMEDOWN},
    {"VOLUMEUP", DIK_VOLUMEUP},
    {"WEBHOME", DIK_WEBHOME},
    {"NUMPADCOMMA", DIK_NUMPADCOMMA},
    {"DIVIDE", DIK_DIVIDE},
    {"SYSRQ", DIK_SYSRQ},
    {"RMENU", DIK_RMENU},
    {"PAUSE", DIK_PAUSE},
    {"HOME", DIK_HOME},
    {"UP", DIK_UP},
    {"PRIOR", DIK_PRIOR},
    {"LEFT", DIK_LEFT},
    {"RIGHT", DIK_RIGHT},
    {"END", DIK_END},
    {"DOWN", DIK_DOWN},
    {"NEXT", DIK_NEXT},
    {"INSERT", DIK_INSERT},
    {"DELETE", DIK_DELETE},
    {"LWIN", DIK_LWIN},
    {"RWIN", DIK_RWIN},
    {"APPS", DIK_APPS},
    {"POWER", DIK_POWER},
    {"SLEEP", DIK_SLEEP},
    {"WAKE", DIK_WAKE},
    {"WEBSEARCH", DIK_WEBSEARCH},
    {"WEBFAVORITES", DIK_WEBFAVORITES},
    {"WEBREFRESH", DIK_WEBREFRESH},
    {"WEBSTOP", DIK_WEBSTOP},
    {"WEBFORWARD", DIK_WEBFORWARD},
    {"WEBBACK", DIK_WEBBACK},
    {"MYCOMPUTER", DIK_MYCOMPUTER},
    {"MAIL", DIK_MAIL},
    {"MEDIASELECT", DIK_MEDIASELECT}
};

Key getKeyCode(const std::string &name);

#endif
