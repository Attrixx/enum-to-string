#include <cassert>
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

	// Convert strings to enums
	auto colorOption = string_to_enum<Color>("Green");
	if (!colorOption.has_value()) return 1; // Ensure the provided string exists in the enum. It is recommended to assert if you use this.
	Color newColor = *colorOption; // The value of this variable is Color::Green.	
}
