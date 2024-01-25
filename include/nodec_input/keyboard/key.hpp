#ifndef NODEC_INPUT__KEYBOARD__KEY_HPP_
#define NODEC_INPUT__KEYBOARD__KEY_HPP_

#include <array>
#include <cstdint>
#include <sstream>
#include <unordered_map>

namespace nodec_input {
namespace keyboard {

// Each code value is based on the following specifications.
//  Windows:
//      * https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
//  Qt:
//      * https://doc.qt.io/qt-6/qt.html#Key-enum
//
//  Unity:
//      * https://docs.unity3d.com/2021.2/Documentation/ScriptReference/KeyCode.html

enum class Key : std::uint32_t {
    None = 0x00,

    Return = 0x0D,
    Escape = 0x1B,

    Space = 0x20, // ' '

    LeftArrow = 0x25,
    UpArrow = 0x26,
    RightArrow = 0x27,
    DownArrow = 0x28,

    Alpha0 = 0x30, // The '0' key on the top of the alphanumeric keyboard.
    Alpha1 = 0x31,
    Alpha2 = 0x32,
    Alpha3 = 0x33,
    Alpha4 = 0x34,
    Alpha5 = 0x35,
    Alpha6 = 0x36,
    Alpha7 = 0x37,
    Alpha8 = 0x38,
    Alpha9 = 0x39,

    A = 0x41, // 'A'
    B = 0x42, // 'B'
    C = 0x43, // 'C'
    D = 0x44, // 'D'
    E = 0x45, // 'E'
    F = 0x46, // 'F'
    G = 0x47, // 'G'
    H = 0x48, // 'H'
    I = 0x49, // 'I'
    J = 0x4A, // 'J'
    K = 0x4B, // 'K'
    L = 0x4C, // 'L'
    M = 0x4D, // 'M'
    N = 0x4E, // 'N'
    O = 0x4F, // 'O'
    P = 0x50, // 'P'
    Q = 0x51, // 'Q'
    R = 0x52, // 'R'
    S = 0x53, // 'S'
    T = 0x54, // 'T'
    U = 0x55, // 'U'
    V = 0x56, // 'V'
    W = 0x57, // 'W'
    X = 0x58, // 'X'
    Y = 0x59, // 'Y'
    Z = 0x5A, // 'Z'

    F1 = 0x70,
    F2 = 0x71,
    F3 = 0x72,
    F4 = 0x73,
    F5 = 0x74,
    F6 = 0x75,
    F7 = 0x76,
    F8 = 0x77,
    F9 = 0x78,
    F10 = 0x79,
    F11 = 0x7A,
    F12 = 0x7B,
    F13 = 0x7C,
    F14 = 0x7D,
    F15 = 0x7E,
    F16 = 0x7F,
    F17 = 0x80,
    F18 = 0x81,
    F19 = 0x82,
    F20 = 0x83,
    F21 = 0x84,
    F22 = 0x85,
    F23 = 0x86,
    F24 = 0x87,
};

struct KeyNameMap {
    static const char *get_name(Key key) {
        static const std::unordered_map<Key, const char *> key_name_map{
            {Key::None, "None"},
            {Key::Return, "Return"},
            {Key::Escape, "Escape"},

            {Key::Space, "Space"},

            {Key::LeftArrow, "LeftArrow"},
            {Key::UpArrow, "UpArrow"},
            {Key::RightArrow, "RightArrow"},
            {Key::DownArrow, "DownArrow"},

            {Key::Alpha0, "Alpha0"},
            {Key::Alpha1, "Alpha1"},
            {Key::Alpha2, "Alpha2"},
            {Key::Alpha3, "Alpha3"},
            {Key::Alpha4, "Alpha4"},
            {Key::Alpha5, "Alpha5"},
            {Key::Alpha6, "Alpha6"},
            {Key::Alpha7, "Alpha7"},
            {Key::Alpha8, "Alpha8"},
            {Key::Alpha9, "Alpha9"},

            {Key::A, "A"},
            {Key::B, "B"},
            {Key::C, "C"},
            {Key::D, "D"},
            {Key::E, "E"},
            {Key::F, "F"},
            {Key::G, "G"},
            {Key::H, "H"},
            {Key::I, "I"},
            {Key::J, "J"},
            {Key::K, "K"},
            {Key::L, "L"},
            {Key::M, "M"},
            {Key::N, "N"},
            {Key::O, "O"},
            {Key::P, "P"},
            {Key::Q, "Q"},
            {Key::R, "R"},
            {Key::S, "S"},
            {Key::T, "T"},
            {Key::U, "U"},
            {Key::V, "V"},
            {Key::W, "W"},
            {Key::X, "X"},
            {Key::Y, "Y"},
            {Key::Z, "Z"},

            {Key::F1, "F1"},
            {Key::F2, "F2"},
            {Key::F3, "F3"},
            {Key::F4, "F4"},
            {Key::F5, "F5"},
            {Key::F6, "F6"},
            {Key::F7, "F7"},
            {Key::F8, "F8"},
            {Key::F9, "F9"},
            {Key::F10, "F10"},
            {Key::F11, "F11"},
            {Key::F12, "F12"},
            {Key::F13, "F13"},
            {Key::F14, "F14"},
            {Key::F15, "F15"},
            {Key::F16, "F16"},
            {Key::F17, "F17"},
            {Key::F18, "F18"},
            {Key::F19, "F19"},
            {Key::F20, "F20"},
            {Key::F21, "F21"},
            {Key::F22, "F22"},
            {Key::F23, "F23"},
            {Key::F24, "F24"},
        };
        auto iter = key_name_map.find(key);
        if (iter == key_name_map.end()) {
            return "Unknown";
        }
        return iter->second;
    }
};

inline std::ostream &operator<<(std::ostream &stream, const Key &key) {
    return stream << KeyNameMap::get_name(key);
}

} // namespace keyboard
} // namespace nodec_input

#endif