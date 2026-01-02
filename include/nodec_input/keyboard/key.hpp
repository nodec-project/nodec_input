#ifndef NODEC_INPUT__KEYBOARD__KEY_HPP_
#define NODEC_INPUT__KEYBOARD__KEY_HPP_

#include <array>
#include <cstdint>
#include <sstream>
#include <unordered_map>

namespace nodec_input {
namespace keyboard {

// Key codes based on Windows Virtual Key Codes.
// Cross-platform implementations should map platform-specific codes to these values.
//
// References:
//  Windows: https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
//  macOS:   Requires mapping from kVK_* codes (HIToolbox/Events.h)
//  Linux:   Requires mapping from KEY_* codes (linux/input-event-codes.h)

enum class Key : std::uint32_t {
    None = 0x00,

    // --- Control keys ---
    Backspace = 0x08,
    Tab = 0x09,
    Clear = 0x0C,
    Return = 0x0D,
    Pause = 0x13,
    CapsLock = 0x14,
    Escape = 0x1B,
    Space = 0x20,

    // --- Navigation keys ---
    PageUp = 0x21,
    PageDown = 0x22,
    End = 0x23,
    Home = 0x24,
    LeftArrow = 0x25,
    UpArrow = 0x26,
    RightArrow = 0x27,
    DownArrow = 0x28,
    Select = 0x29,
    Print = 0x2A,
    Execute = 0x2B,
    PrintScreen = 0x2C,
    Insert = 0x2D,
    Delete = 0x2E,
    Help = 0x2F,

    // --- Alphanumeric keys (top row) ---
    Alpha0 = 0x30,
    Alpha1 = 0x31,
    Alpha2 = 0x32,
    Alpha3 = 0x33,
    Alpha4 = 0x34,
    Alpha5 = 0x35,
    Alpha6 = 0x36,
    Alpha7 = 0x37,
    Alpha8 = 0x38,
    Alpha9 = 0x39,

    // --- Letter keys ---
    A = 0x41,
    B = 0x42,
    C = 0x43,
    D = 0x44,
    E = 0x45,
    F = 0x46,
    G = 0x47,
    H = 0x48,
    I = 0x49,
    J = 0x4A,
    K = 0x4B,
    L = 0x4C,
    M = 0x4D,
    N = 0x4E,
    O = 0x4F,
    P = 0x50,
    Q = 0x51,
    R = 0x52,
    S = 0x53,
    T = 0x54,
    U = 0x55,
    V = 0x56,
    W = 0x57,
    X = 0x58,
    Y = 0x59,
    Z = 0x5A,

    // --- Windows/Command keys ---
    LeftWindows = 0x5B,
    RightWindows = 0x5C,
    Apps = 0x5D,  // Applications/Context menu key
    Sleep = 0x5F,

    // --- Numpad keys ---
    Numpad0 = 0x60,
    Numpad1 = 0x61,
    Numpad2 = 0x62,
    Numpad3 = 0x63,
    Numpad4 = 0x64,
    Numpad5 = 0x65,
    Numpad6 = 0x66,
    Numpad7 = 0x67,
    Numpad8 = 0x68,
    Numpad9 = 0x69,
    NumpadMultiply = 0x6A,
    NumpadAdd = 0x6B,
    NumpadSeparator = 0x6C,
    NumpadSubtract = 0x6D,
    NumpadDecimal = 0x6E,
    NumpadDivide = 0x6F,

    // --- Function keys ---
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

    // --- Lock keys ---
    NumLock = 0x90,
    ScrollLock = 0x91,

    // --- Modifier keys (left/right specific) ---
    LeftShift = 0xA0,
    RightShift = 0xA1,
    LeftControl = 0xA2,
    RightControl = 0xA3,
    LeftAlt = 0xA4,
    RightAlt = 0xA5,

    // --- Browser keys ---
    BrowserBack = 0xA6,
    BrowserForward = 0xA7,
    BrowserRefresh = 0xA8,
    BrowserStop = 0xA9,
    BrowserSearch = 0xAA,
    BrowserFavorites = 0xAB,
    BrowserHome = 0xAC,

    // --- Media keys ---
    VolumeMute = 0xAD,
    VolumeDown = 0xAE,
    VolumeUp = 0xAF,
    MediaNextTrack = 0xB0,
    MediaPrevTrack = 0xB1,
    MediaStop = 0xB2,
    MediaPlayPause = 0xB3,
    LaunchMail = 0xB4,
    LaunchMediaSelect = 0xB5,
    LaunchApp1 = 0xB6,
    LaunchApp2 = 0xB7,

    // --- Punctuation keys (layout-dependent) ---
    // These keys represent physical positions. The character produced varies by keyboard layout.
    // Names follow SDL/GLFW convention (character name based on US ANSI layout).
    //
    // Cross-platform mapping:
    //   Windows: VK_OEM_* codes (values shown below)
    //   macOS:   kVK_ANSI_* codes from HIToolbox/Events.h (different values, requires mapping)
    //   Linux:   KEY_* codes from linux/input-event-codes.h (different values, requires mapping)

    // Physical key: Right of L key
    // US: ;: | JIS: ;+ | German: Ö
    Semicolon = 0xBA,

    // Physical key: Left of Backspace (top row)
    // US: =+ | JIS: ^~ | German: ´`
    Equals = 0xBB,

    // Physical key: Right of M key
    // US: ,< | JIS: ,< | German: ,;
    Comma = 0xBC,

    // Physical key: Right of 0 key (top row)
    // US: -_ | JIS: -=  | German: ß?
    Minus = 0xBD,

    // Physical key: Right of Comma key
    // US: .> | JIS: .> | German: .:
    Period = 0xBE,

    // Physical key: Right of Period key
    // US: /? | JIS: /? | German: -_
    Slash = 0xBF,

    // Physical key: Left of 1 key (top row)
    // US: `~ | JIS: (Hankaku/Zenkaku) | German: ^°
    Grave = 0xC0,

    // Physical key: Right of P key
    // US: [{ | JIS: @` | German: Ü
    LeftBracket = 0xDB,

    // Physical key: Above Return key (varies by layout)
    // US: \| | JIS: ]~ | German: #'
    Backslash = 0xDC,

    // Physical key: Right of LeftBracket key
    // US: ]} | JIS: [{ | German: +*
    RightBracket = 0xDD,

    // Physical key: Right of Semicolon key
    // US: '" | JIS: :* | German: Ä
    Apostrophe = 0xDE,

    // --- Maximum value marker ---
    // Used for array sizing. All valid key codes are < KeyCount.
    // 0xFF (255) is reserved/undefined in Windows VK codes.
    KeyCount = 0x100,  // 256 - covers all Windows VK codes (0x00-0xFE)
};

// Convenience constant for bitset/array sizing
inline constexpr std::size_t key_count = static_cast<std::size_t>(Key::KeyCount);

struct KeyNameMap {
    static const char *get_name(Key key) {
        static const std::unordered_map<Key, const char *> key_name_map{
            {Key::None, "None"},

            // Control keys
            {Key::Backspace, "Backspace"},
            {Key::Tab, "Tab"},
            {Key::Clear, "Clear"},
            {Key::Return, "Return"},
            {Key::Pause, "Pause"},
            {Key::CapsLock, "CapsLock"},
            {Key::Escape, "Escape"},
            {Key::Space, "Space"},

            // Navigation keys
            {Key::PageUp, "PageUp"},
            {Key::PageDown, "PageDown"},
            {Key::End, "End"},
            {Key::Home, "Home"},
            {Key::LeftArrow, "LeftArrow"},
            {Key::UpArrow, "UpArrow"},
            {Key::RightArrow, "RightArrow"},
            {Key::DownArrow, "DownArrow"},
            {Key::Select, "Select"},
            {Key::Print, "Print"},
            {Key::Execute, "Execute"},
            {Key::PrintScreen, "PrintScreen"},
            {Key::Insert, "Insert"},
            {Key::Delete, "Delete"},
            {Key::Help, "Help"},

            // Alphanumeric keys
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

            // Letter keys
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

            // Windows/Command keys
            {Key::LeftWindows, "LeftWindows"},
            {Key::RightWindows, "RightWindows"},
            {Key::Apps, "Apps"},
            {Key::Sleep, "Sleep"},

            // Numpad keys
            {Key::Numpad0, "Numpad0"},
            {Key::Numpad1, "Numpad1"},
            {Key::Numpad2, "Numpad2"},
            {Key::Numpad3, "Numpad3"},
            {Key::Numpad4, "Numpad4"},
            {Key::Numpad5, "Numpad5"},
            {Key::Numpad6, "Numpad6"},
            {Key::Numpad7, "Numpad7"},
            {Key::Numpad8, "Numpad8"},
            {Key::Numpad9, "Numpad9"},
            {Key::NumpadMultiply, "NumpadMultiply"},
            {Key::NumpadAdd, "NumpadAdd"},
            {Key::NumpadSeparator, "NumpadSeparator"},
            {Key::NumpadSubtract, "NumpadSubtract"},
            {Key::NumpadDecimal, "NumpadDecimal"},
            {Key::NumpadDivide, "NumpadDivide"},

            // Function keys
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

            // Lock keys
            {Key::NumLock, "NumLock"},
            {Key::ScrollLock, "ScrollLock"},

            // Modifier keys
            {Key::LeftShift, "LeftShift"},
            {Key::RightShift, "RightShift"},
            {Key::LeftControl, "LeftControl"},
            {Key::RightControl, "RightControl"},
            {Key::LeftAlt, "LeftAlt"},
            {Key::RightAlt, "RightAlt"},

            // Browser keys
            {Key::BrowserBack, "BrowserBack"},
            {Key::BrowserForward, "BrowserForward"},
            {Key::BrowserRefresh, "BrowserRefresh"},
            {Key::BrowserStop, "BrowserStop"},
            {Key::BrowserSearch, "BrowserSearch"},
            {Key::BrowserFavorites, "BrowserFavorites"},
            {Key::BrowserHome, "BrowserHome"},

            // Media keys
            {Key::VolumeMute, "VolumeMute"},
            {Key::VolumeDown, "VolumeDown"},
            {Key::VolumeUp, "VolumeUp"},
            {Key::MediaNextTrack, "MediaNextTrack"},
            {Key::MediaPrevTrack, "MediaPrevTrack"},
            {Key::MediaStop, "MediaStop"},
            {Key::MediaPlayPause, "MediaPlayPause"},
            {Key::LaunchMail, "LaunchMail"},
            {Key::LaunchMediaSelect, "LaunchMediaSelect"},
            {Key::LaunchApp1, "LaunchApp1"},
            {Key::LaunchApp2, "LaunchApp2"},

            // Punctuation keys
            {Key::Semicolon, "Semicolon"},
            {Key::Equals, "Equals"},
            {Key::Comma, "Comma"},
            {Key::Minus, "Minus"},
            {Key::Period, "Period"},
            {Key::Slash, "Slash"},
            {Key::Grave, "Grave"},
            {Key::LeftBracket, "LeftBracket"},
            {Key::Backslash, "Backslash"},
            {Key::RightBracket, "RightBracket"},
            {Key::Apostrophe, "Apostrophe"},
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
