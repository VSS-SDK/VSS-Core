//
// Created by johnathan on 27/05/18.
//

#ifndef VSS_CORE_COMMANDSENDER_H
#define VSS_CORE_COMMANDSENDER_H

#include <Interfaces/ICommandSender.h>
#include <zmq.hpp>
#include <command.pb.h>
#include "Domain/TeamType.h"
#include "Domain/Command.h"

namespace vss {

    class CommandSender : public ICommandSender {
    public:
        CommandSender();

        void createSocket(TeamType) override;
        void sendCommand(Command) override;

    protected:
        zmq::context_t *context;
        zmq::socket_t *socket;
        std::string address;

        void SetupAddress(TeamType);
    };

}

#endif //VSS_CORE_COMMANDSENDER_H
