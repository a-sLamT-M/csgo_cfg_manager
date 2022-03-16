//
// Created by Lam T(offline) on 2022/3/14.
//

#ifndef CSGO_CFG_MANAGER_UTILS_H
#define CSGO_CFG_MANAGER_UTILS_H

#include <string>
#include <Windows.h>
#include <QString>
#include <memory>

namespace ct_wu
{
    class Utils
    {
    public:
        Utils() = default;

        template<typename T>
        wchar_t * string_to_wchar_t(const T &T_string);
        std::string * wchar_t_to_string(const wchar_t *wchar);
    };
}


#endif //CSGO_CFG_MANAGER_UTILS_H
