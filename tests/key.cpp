#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

#include <nodec_input/keyboard/key.hpp>

TEST_CASE("Testing KeyNameMap.") {
    using namespace nodec_input::keyboard;

    CHECK(KeyNameMap::get_name(Key::None) == std::string("None"));
    CHECK(KeyNameMap::get_name(Key::A) == std::string("A"));
    CHECK(KeyNameMap::get_name(Key::Z) == std::string("Z"));
}

TEST_CASE("Testing ostream operator<< for Key.") {
    using namespace nodec_input::keyboard;

    std::stringstream ss;
    ss << Key::A;
    CHECK(ss.str() == std::string("A"));
}