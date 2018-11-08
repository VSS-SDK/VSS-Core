//
// Created by johnathan on 27/05/18.
//

#ifndef VSS_CORE_ICOMMANDSENDER_H
#define VSS_CORE_ICOMMANDSENDER_H

#include <Domain/Address.h>
#include <Domain/ExecutionConfig.h>
#include <zmq.hpp>
#include "iostream"
#include "Domain/TeamType.h"
#include "Domain/Command.h"

namespace vss {

    class ICommandSender {
    public:
        virtual void createSocket(ExecutionConfig&) = 0;
        virtual void createSocket(Address) = 0;
        virtual void createSocket(TeamType) = 0;
        virtual void closeSocket() = 0;
        virtual void sendCommand(Command) = 0;

        virtual ~ICommandSender();

    protected:
        zmq::context_t *context;
        zmq::socket_t *socket;
        Address address;
    };

    ICommandSender::~ICommandSender() {
        socket->close();
        delete socket;
        delete context;
    }

}

#endif //VSS_CORE_ICOMMANDSENDER_H
