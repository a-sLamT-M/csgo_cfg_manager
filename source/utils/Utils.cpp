#include <sys/stat.h>
#include "Utils.h"

template<typename T>
wchar_t * ct_wu::Utils::string_to_wchar_t(const T &T_string) const
{
    std::string std_string = nullptr;

    if (typeid(T_string) == typeid(QString))
        std_string = T_string.toStdString();
    else
        std_string = std::to_string(T_string);

    std::wstring wstr(std_string.length(), L' ');
    std::copy(std_string.begin(), std_string.end(), wstr.begin());
    return _wcsdup(wstr.c_str());
}

std::string * ct_wu::Utils::wchar_t_to_string(const wchar_t *wchar) const
{
    std::wstring wstr(wchar);
    std::string str(wstr.begin(), wstr.end());
    return new std::string(str);
}

bool ct_wu::Utils::isFolderExist(const std::string path)
{
    struct stat info{};
    return (stat(path.c_str(), &info) == 0 && (info.st_mode & S_IFDIR));
}

bool ct_wu::Utils::isFileExist(const std::string path)
{
    struct stat info{};
    return (stat(path.c_str(), &info) == 0 && (info.st_mode & S_IFREG));
}
