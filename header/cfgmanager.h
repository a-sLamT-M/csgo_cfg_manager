#ifndef CFGMANAGER_H
#define CFGMANAGER_H

#include <string>
#include "exceptions/invalid_path_exception.h"
#include <sys/stat.h>

class CfgManager
{
public:
    CfgManager();
    CfgManager(const std::string &csgoCl): csgoCatalog(csgoCl)
    { getSteamPathFromSystem(); }
    CfgManager(const std::string &&csgoCl): csgoCatalog(csgoCl)
    { getSteamPathFromSystem(); }

    CfgManager(const std::string &csgoCl, const std::string &steamCl):
        csgoCatalog(csgoCl), steamCatalog(steamCl) {};
    CfgManager(const std::string &&csgoCl, const std::string &&steamCl):
        csgoCatalog(csgoCl), steamCatalog(steamCl){};

    ~CfgManager() = default;

    const std::string getCsgoCatalog() const {return csgoCatalog; }
    const std::string getCsgoPathFromSystem();
    const std::string getSteamPathFromSystem();

    void setCsgoCatalog(const std::string &csgoCl);
    void setCsgoCatalog(const std::string &&csgoCl);

    bool checkPathValid(const std::string path) const;


private:
    std::string csgoCatalog = "";
    std::string steamCatalog = "";
};

#endif // CFGMANAGER_H
