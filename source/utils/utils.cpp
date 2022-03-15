//
// Created by Lam T on 2022/3/14.
//

#include "utils.h"

template<typename T>
const wchar_t * ct_wu::utils::string_to_wchar_t(const T &T_string) const
{
    std::string std_string = nullptr;

    if (typeid(T_string) == typeid(QString))
        std_string = T_string.toStdString();
    else
        std_string = std::to_string(T_string);

    const char * smart_c_string = std_string.c_str();
    auto *w_string = new WCHAR[std_string.length() + 1];

    MultiByteToWideChar(CP_UTF8, 0, smart_c_string, -1, w_string, std_string.length() + 1);
    delete smart_c_string;
    return w_string;
}