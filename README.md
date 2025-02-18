# C++ enum-to-string

Easy way to convert enums to string. All the code generation is done during compile time, so it does not cost any runtime performance.
It is compatible with MSVC (Visual Studio), GCC & clang.

## Integration

### How to import

Simply import the file in your project and include it. C++ 20 is required to compile this file since it uses concepts.

### How to use

You can either call `enum_to_string(enum::value)` with your enum value as argument or `<< enum::value`, both return a `std::string_view`

## Limits

All your enums must have a lower amount of values than the specified int in the array constructor (aka 256). You can still change this value for a higher one if needed, but it is not recommanded
