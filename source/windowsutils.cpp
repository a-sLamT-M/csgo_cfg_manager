#include "../header/windowsutils.h"


const std::string * ct_wu::WindowsUtils::getRegVal(const std::string& path, HKEY__ *rootKey, const std::string& name)
{
    std::unique_ptr<ct_wu::Utils> utils(new ct_wu::Utils());

    HKEY hkey = nullptr;
    wchar_t cresult[1024];
    DWORD szModule = MAXDWORD;

    wchar_t *wpath = utils->string_to_wchar_t(path);
    wchar_t *wname = utils->string_to_wchar_t(name);

    LPCTSTR hData = wpath;

    auto isSuccess = RegOpenKeyEx(rootKey,
                                  hData,
                                  0,
                                  KEY_READ,
                                  &hkey);

    auto isSuccess2 = RegQueryValueEx(
            hkey,
            wname,
            nullptr,
            nullptr,
            (LPBYTE) &cresult,
            &szModule);

    std::string *str = utils->wchar_t_to_string(cresult);

    wpath = nullptr;
    wname = nullptr;
    delete wname;
    delete wpath;

    if (isSuccess)
    {
        throw reg_exception
        ("Failed to read Reg Value. Code: "
        + std::to_string(isSuccess)
        + " - " + path
        + " - " + name);
    }
    if (isSuccess2)
    {
        throw reg_exception
        ("Failed to read Reg Value. Code: " + std::to_string(isSuccess2)
        + " - " + path
        + " - " + name);
    }

    return str;
}
