# C++ enum-to-string

Easy way to convert enums to strings. All operations are done in compile time, so it does not cost any runtime performance.
It is compatible with MSVC (Visual Studio), GCC & clang. C++ 20 is required to compile this file since it uses concepts.

## Integration

### How to import

Simply import the file `enum_to_string.h` in your project and include it. You can refer to `example.cpp` if you have any issue.

### How to use

You can either call `enum_to_string(enum::value)` which returns a `std::string_view` or `osteam << enum::value` for outputs.

## Limits

All your enums must have a lower amount of values than the specified int in the array constructor (aka 256).
You can still change this value for a higher one if needed, but it is not recommanded.
If you need compatibility of this file with a currently unsupported compiler, feel free to open an issue. I will patch it as soon as I can.
