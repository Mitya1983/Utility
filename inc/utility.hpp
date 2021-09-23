#ifndef UTILITY_HPP
#define UTILITY_HPP


#include <string>

namespace tristan {

auto wstring_to_string(const std::wstring &wstring) -> std::string;
auto string_to_wstring(const std::string &string) -> std::wstring;
auto to_string(float value, uint8_t precision = 2) -> std::string;
auto to_wstring(float value, uint8_t precision = 2) -> std::wstring;


} // namespace tristan


#endif // UTILITY_HPP
