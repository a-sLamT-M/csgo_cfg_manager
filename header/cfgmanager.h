#ifndef CFGMANAGER_H
#define CFGMANAGER_H

#include <string>
#include <sys/stat.h>
#include <memory>
#include "exceptions/files_does_not_exist_exception.h"
#include "exceptions/invalid_path_exception.h"
#include "windowsutils.h"

class CfgManager
{
public:
    CfgManager();
    CfgManager(const std::string &csgoCl): csgoCatalog(csgoCl)
    {
        getSteamPathFromSystem();
    }

    CfgManager(const std::string &csgoCl, const std::string &steamCl):
        csgoCatalog(csgoCl), steamCatalog(steamCl) {};

    ~CfgManager() = default;

    const std::string getCsgoCatalog() const {return csgoCatalog; }
    const std::string getCsgoPathFromSystem();
    std::string getSteamPathFromSystem();

    void setCsgoCatalog(const std::string &csgoCl);

    bool checkPathValid(const std::string path) const;


private:
    std::string csgoCatalog = nullptr;
    std::string steamCatalog = nullptr;
};

#endif // CFGMANAGER_H
