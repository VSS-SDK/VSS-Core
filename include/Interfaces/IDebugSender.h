//
// Created by johnathan on 27/05/18.
//

#ifndef VSS_CORE_IDEBUGSENDER_H
#define VSS_CORE_IDEBUGSENDER_H

#include "Domain/TeamType.h"
#include "Domain/Debug.h"

namespace vss {
    class IDebugSender {
    public:
        virtual void createSocket(TeamType) = 0;
        virtual void sendDebug(Debug) = 0;
        virtual void setAddress(std::string) = 0;
    };
}

#endif //VSS_CORE_IDEBUGSENDER_H
