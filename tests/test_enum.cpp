#include <cassert>
#include <iostream>

#include "../enum_to_string.h"

enum class Test : char
{
    ONE,
    TWO,
    THREE
};

int main() {
    std::cout << "Running Enum Tests...\n";

    // enum -> string
    assert(enum_to_string(Test::ONE) == "ONE");
    assert(enum_to_string(Test::TWO) == "TWO");

    std::string_view three = enum_to_string(Test::THREE);
    assert(three = "THREE");

    // string -> enum
    auto invalidOpt = string_to_enum<Test>("Whatever");
    auto validOpt = string_to_enum<Test>("THREE");

    assert(!invalidOpt.has_value());
    assert(validOpt.has_value());
    assert(*validOpt == Test::THREE);

    std::cout << "All tests passed!\n";
    return 0;
}
