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

        wchar_t * std_string_to_wchar_t(const std::string &);
        std::string * wchar_t_to_std_string(const wchar_t *);
    };
}


#endif //CSGO_CFG_MANAGER_UTILS_H
