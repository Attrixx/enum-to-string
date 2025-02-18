#include <array>
#include <iostream>
#include <string_view>

template<typename T>
concept enumeration = std::is_enum_v<T>;

template<enumeration auto V>
constexpr std::string_view extract_enum_name() noexcept
{
#ifdef _MSC_VER
    constexpr std::string_view func = __FUNCSIG__;
    constexpr std::size_t start = 92Ui64;
    constexpr std::size_t end = func.size() - 16Ui64;
#elif defined(__clang__)
    constexpr std::string_view func = __PRETTY_FUNCTION__;
    constexpr std::size_t start = 42;
    constexpr std::size_t end = func.size() - 1;
#elif defined(__GNUC__)
    constexpr std::string_view func = __PRETTY_FUNCTION__;
    constexpr std::size_t start = 104;
    constexpr std::size_t end = func.size() - 50;
#else
#error "Compiler not supported"
#endif
    constexpr std::string_view full_enum = func.substr(start, end - start);
    constexpr size_t pos = full_enum.rfind("::");
    return full_enum.substr(pos + 2);
}

template <enumeration T, std::size_t... I>
constexpr auto scan_enum_values(std::index_sequence<I...>)
{
    return std::array<std::pair<T, std::string_view>, sizeof...(I)>
    {
        { { static_cast<T>(I), extract_enum_name<static_cast<T>(I)>() }... }
    };
}

template<typename T>
struct enum_traits
{
    static constexpr auto values = scan_enum_values<T>(std::make_index_sequence<256>{});
};

template<enumeration T>
inline constexpr std::string_view enum_to_string(T value)
{
    for (const auto& [enum_value, str] : enum_traits<T>::values)
    {
        if (enum_value == value)
        {
            return str;
        }
    }
    return std::string_view();
}

template<enumeration T>
std::ostream& operator<<(std::ostream& os, T value)
{
    return os << enum_to_string(value);
}
