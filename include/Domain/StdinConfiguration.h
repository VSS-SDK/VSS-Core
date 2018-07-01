//
// Created by johnathan on 01/07/18.
//

#ifndef VSS_CORE_STDINCONFIGURATION_H
#define VSS_CORE_STDINCONFIGURATION_H

#include "Domain/Address.h"
#include "Domain/TeamType.h"
#include "Domain/SideAttackType.h"
#include "Domain/TimeExecutionType.h"
#include "Domain/EnvironmentType.h"

namespace vss {

    class StdinConfiguration {
    public:
        StdinConfiguration();

        friend std::ostream& operator<<(std::ostream& os, const StdinConfiguration& state);

        Address stateReceiverAddress;
        Address stateSenderAddress;
        Address commandYellowReceiverAddress;
        Address commandYellowSenderAddress;
        Address debugYellowReceiverAddress;
        Address debugYellowSenderAddress;
        Address commandBlueReceiverAddress;
        Address commandBlueSenderAddress;
        Address debugBlueReceiverAddress;
        Address debugBlueSenderAddress;

        Address controlReceiverAddress;
        Address controlSenderAddress;

        TeamType teamType;
        SideAttackType sideAttackType;
        TimeExecutionType timeExecutionType;
        EnvironmentType environmentType;

        bool validConfiguration;
    };

}

#endif //VSS_CORE_STDINCONFIGURATION_H
