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

        friend std::ostream& operator<<(std::ostream& os, const ExecutionConfig& executionConfig);

        Address stateRecvAddr;
        Address stateSendAddr;

        Address cmdYellowRecvAddr;
        Address cmdYellowSendAddr;
        Address debugYellowRecvAddr;
        Address debugYellowSendAddr;

        Address cmdBlueRecvAddr;
        Address cmdBlueSendAddr;
        Address debugBlueRecvAddr;
        Address debugBlueSendAddr;

        Address ctrlRecvAddr;
        Address ctrlSendAddr;

        TeamType teamType;
        SideAttackType sideAttackType;
        TimeExecutionType timeExecutionType;
        EnvironmentType environmentType;

        bool isValidConfiguration;
    };

}

#endif //VSS_CORE_STDINCONFIGURATION_H
