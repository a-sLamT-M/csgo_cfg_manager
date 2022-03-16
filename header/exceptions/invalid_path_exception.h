#ifndef INVALID_PATH_EXCEPTION_H
#define INVALID_PATH_EXCEPTION_H

#include "csgo_cfg_runtime_exception.h"
#include <string>

class invalid_path_exception : public csgo_cfg_runtime_exception
{
public:
    explicit invalid_path_exception(const std::string &s) : path(s)
    {
        information = ("Invalid Path: " + path).c_str();
    }

    ~invalid_path_exception() override { delete information; }

    [[nodiscard]] const char * what () const noexcept override
    {
        return information;
    }

private:
    const char *information;
    std::string path;
};

#endif // INVALID_PATH_EXCEPTION_H
