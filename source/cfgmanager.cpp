#include "../header/cfgmanager.h"
#include "../header/windowsutils.h"
CfgManager::CfgManager()
{
    try
    {
        #if defined (_WIN32) || defined (_WIN64)
        getSteamPathFromSystem();
        getCsgoPathFromSystem();
        #endif
    }
    catch (files_does_not_exist_exception e)
    {
#if defined(_WIN32)
        CfgManager::csgoCatalog = R"(C:\Program Files\Steam\Steamapps\Counter-Strike Global Offensive)";
        CfgManager::steamCatalog = R"(C:\Program Files\Steam)";
#endif
#if defined(_WIN64)
        CfgManager::csgoCatalog = R"(C:\Program Files (86)\Steam\Steamapps\Counter-Strike Global Offensive)";
        CfgManager::steamCatalog = R"(C:\Program Files (86)\Steam)";
#endif
#if !defined (_WIN32) || !defined (_WIN64)
        CfgManager::csgoCatalog = "";
        CfgManager::steamCatalog = "";
#endif
    }
}

void CfgManager::setCsgoCatalog(const std::string &csgoCl)
{
    try
    {
        if (ct_wu::Utils::isFolderExist(csgoCl))
        {
            csgoCatalog = csgoCl;
        }
        else
        {
            throw invalid_path_exception(csgoCl);
        }
    }
    catch (invalid_path_exception e)
    {
        // 显示一个窗口，表示这路径有误
    }
}

const std::string CfgManager::getCsgoPathFromSystem()
{
    return nullptr;
}

std::string CfgManager::getSteamPathFromSystem()
{
    ct_wu::WindowsUtils *ut = new ct_wu::WindowsUtils();
    try
    {
        std::string * sP = nullptr;
#if defined(_WIN32)
        sP = ut->getRegVal(R"(HKEY_LOCAL_MACHINE\SOFTWARE\Valve\Steam)", HKEY_LOCAL_MACHINE, "InstallPath");
#endif
#if defined(_WIN64)
        sP = ut->getRegVal(R"(HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\Valve\Steam)", HKEY_LOCAL_MACHINE, "InstallPath");
#endif
        this->steamCatalog = *sP;
        sP = nullptr;
        delete sP;
        return steamCatalog;
    }
    catch (reg_exception)
    {
        // 显示一个窗口，表示注册表打开失败
    }

    //HKEY_LOCAL_MACHINE\SOFTWARE\Valve\Steam 32-bit
    //HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\Valve\Steam 64-bit
}
