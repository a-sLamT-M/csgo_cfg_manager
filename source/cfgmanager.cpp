#include "../header/cfgmanager.h"

#include "../header/exceptions/files_does_not_exist_exception.h"

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
        CfgManager::csgoCatalog = "C://Program Files//Steam//Steamapps//Counter-Strike Global Offensive";
        CfgManager::steamCatalog = "C://Program Files//Steam//";

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
        if (checkPathValid(csgoCl))
        {
            csgoCatalog = csgoCl;
        }
    }
    catch (invalid_path_exception e)
    {
        // 显示一个窗口，表示这路径有误
    }
}

bool CfgManager::checkPathValid(const std::string path) const
{
    struct stat buffer;
    if(!stat(path.c_str(), &buffer))
    {
        throw new invalid_path_exception(path);
    }
    return true;
}

const std::string CfgManager::getCsgoPathFromSystem()
{

}

const std::string CfgManager::getSteamPathFromSystem()
{
    //HKEY_LOCAL_MACHINE\SOFTWARE\Valve\Steam 32-bit
    //HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\Valve\Steam 64-bit
}
