//
// Created by Lam T on 2022/3/14.
//

#include "Utils.h"

wchar_t * ct_wu::Utils::std_string_to_wchar_t(const std::string &T_string)
{
    std::wstring wstr(T_string.length(), L' ');
    std::copy(T_string.begin(), T_string.end(), wstr.begin());
    return _wcsdup(wstr.c_str());
}

std::string * ct_wu::Utils::wchar_t_to_std_string(const wchar_t *wchar)
{
    std::wstring wstr(wchar);
    std::string str(wstr.begin(), wstr.end());
    return new std::string(str);
}