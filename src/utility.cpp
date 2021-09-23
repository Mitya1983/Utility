#include "utility.hpp"

#include <locale>
#include <codecvt>
#include <chrono>
#include <cmath>

std::string tristan::wstring_to_string(const std::wstring &wstring)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;

    return converter.to_bytes(wstring);
}

std::wstring tristan::string_to_wstring(const std::string &string)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;

    return converter.from_bytes(string);
}

std::string tristan::to_string(float value, uint8_t precision)
{
    float intpart;
    float remainderPart = std::modf(value, &intpart);
    remainderPart *= std::pow(10, precision);
    remainderPart = std::round(remainderPart);
    std::string returnValue = std::to_string(static_cast<int>(intpart)) + ',';
    if (remainderPart == 0){
        returnValue += "00";
    }
    else if (remainderPart < 10) {
        remainderPart *= 10;
        returnValue += std::to_string(static_cast<int>(remainderPart));
    }
    else{
        returnValue += std::to_string(static_cast<int>(remainderPart));
    }

    return returnValue;
}

std::wstring tristan::to_wstring(float value, uint8_t precision)
{
    auto string_value = tristan::to_string(value, precision);

    return tristan::string_to_wstring(string_value);
}
