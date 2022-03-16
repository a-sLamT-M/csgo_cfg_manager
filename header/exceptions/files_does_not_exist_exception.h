#ifndef FILES_DOES_NOT_EXIST_EXCEPTION_H
#define FILES_DOES_NOT_EXIST_EXCEPTION_H

#include "csgo_cfg_runtime_exception.h"
#include <string>

class files_does_not_exist_exception : public csgo_cfg_runtime_exception
{
public:
    explicit files_does_not_exist_exception()
    {
        information = "File does no exist.";
    }

    ~files_does_not_exist_exception() override { delete information; }

    [[nodiscard]] const char * what () const noexcept override
    {
        return information;
    }

private:
    const char *information;
};

#endif // FILES_DOES_NOT_EXIST_EXCEPTION_H
