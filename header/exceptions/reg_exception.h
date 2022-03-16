//
// Created by Lam T(offline) on 2022/3/16.
//

#ifndef CSGO_CFG_MANAGER_REG_EXCEPTION_H
#define CSGO_CFG_MANAGER_REG_EXCEPTION_H

#include "csgo_cfg_runtime_exception.h"
#include <string>

class reg_exception : public csgo_cfg_runtime_exception
{
public:
    explicit reg_exception(const std::string &s) : path(s)
    {
        information = path.c_str();
    }

    ~reg_exception() override { delete information; }

    const char * what () const throw () override
    {
        return information;
    }

private:
    const char *information;
    std::string path;
};
};
#endif //CSGO_CFG_MANAGER_REG_EXCEPTION_H
