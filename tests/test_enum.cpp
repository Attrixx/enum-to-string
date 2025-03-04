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

    // Exemples de tests sur ta conversion enum -> string
    assert(enum_to_string(Test::ONE) == "ONE");
    assert(enum_to_string(Test::TWO) == "TWO");

    std::string_view three = enum_to_string(Test::THREE);
    assert(three = "THREE");

    std::cout << "All tests passed!\n";
    return 0;
}
