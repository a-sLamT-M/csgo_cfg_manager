#include "../header/windowsutils.h"

const std::string ct_wu::WindowsUtils::getHEKY(const std::string& path, HKEY__ *rootKey, const std::string& name)
{
    const auto *utl = new ct_wu::utils();
    HKEY hkey = nullptr;
    LPCTSTR hData = utl->string_to_wchar_t(path);
    delete utl;
    long isSuccess = RegOpenKeyEx(rootKey, hData, 0, KEY_READ, &hkey);

    if (isSuccess)
    {
        throw invalid_path_exception(path + "; Code: " + std::to_string(isSuccess));
    }
    else
    {
        RegQueryValueEx(hkey, nullptr, nullptr, nullptr, nullptr, nullptr);
    }
}
