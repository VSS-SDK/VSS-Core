//
// Created by johnathan on 27/05/18.
//

#ifndef VSS_CORE_COMMANDSENDER_H
#define VSS_CORE_COMMANDSENDER_H

#include <Interfaces/ICommandSender.h>
#include <zmq.hpp>
#include "Domain/TeamType.h"
#include "Domain/Command.h"
#include "Communications/CommunicationBase.h"

namespace vss {

    class CommandSender : public ICommandSender, public CommunicationBase {
    public:
        CommandSender();

        void createSocket(TeamType) override;
        void sendCommand(Command) override;

    protected:
        void SetupAddress(TeamType);
    };

}

#endif //VSS_CORE_COMMANDSENDER_H
