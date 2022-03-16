#ifndef CSGO_CFG_RUNTIME_EXCEPTION_H
#define CSGO_CFG_RUNTIME_EXCEPTION_H

#include <exception>

class csgo_cfg_runtime_exception : public std::exception
{
public:
    virtual const char *what () const noexcept override
    {
      return "Unexpected Error.";
    }

    ~csgo_cfg_runtime_exception () override = default;
};

#endif // CSGO_CFG_RUNTIME_EXCEPTION_H
