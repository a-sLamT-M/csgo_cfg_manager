#ifndef WINDOWSUTILS_H
#define WINDOWSUTILS_H

#include <Windows.h>
#include <string>
#include <QMessageBox>
#include "../header/exceptions/invalid_path_exception.h"
#include "../source/utils/utils.h"

namespace ct_wu
{
    class WindowsUtils
    {
    public:
        WindowsUtils() = default;
#if defined (_WIN32)
        const std::string getHEKY(const std::string&, HKEY__ *, const std::string&);
#endif
    };
}



#endif // WINDOWSUTILS_H
