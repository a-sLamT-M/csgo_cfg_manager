#ifndef CSGO_CFG_RUNTIME_EXCEPTION_H
#define CSGO_CFG_RUNTIME_EXCEPTION_H

#include <exception>

class csgo_cfg_runtime_exception : public std::exception
{
public:
    virtual const char *what () const throw ()
    {
      return "Unexpected Error.";
    }

    virtual ~csgo_cfg_runtime_exception () = 0;
};

#endif // CSGO_CFG_RUNTIME_EXCEPTION_H
