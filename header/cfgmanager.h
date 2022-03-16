/*
 * Copyright (c) 2022 Lamportan Techart,
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 *  met:
 *
 *  ** Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *  ** Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

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

private:
    std::string csgoCatalog = nullptr;
    std::string steamCatalog = nullptr;
};

#endif // CFGMANAGER_H
