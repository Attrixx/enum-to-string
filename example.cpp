#include <iostream>

#include "enum_to_string.h"

enum class Color : char
{
	Red,
	Green,
	Blue
};

int main()
{
	// Getting enum names
	std::string_view red = enum_to_string(Color::Red);

	// Displaying enum names
	std::cout << "Red color name is " << red << std::endl;

	// Displaying enum names in place
	std::cout << "Green color name is " << Color::Green << std::endl;

	// Displaying enum variables
	Color currentColor = Color::Blue;
    std::cout << "Current color value is " << currentColor << std::endl;
}
