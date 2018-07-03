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

    class ExecutionConfig {
    public:
        ExecutionConfig();

        friend std::ostream& operator<<(std::ostream& os, const ExecutionConfig& state);

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

        bool isValidConfiguration;
    };

}

#endif //VSS_CORE_STDINCONFIGURATION_H
