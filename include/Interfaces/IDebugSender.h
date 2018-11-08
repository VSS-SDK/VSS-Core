//
// Created by johnathan on 27/05/18.
//

#ifndef VSS_CORE_IDEBUGSENDER_H
#define VSS_CORE_IDEBUGSENDER_H

#include <Domain/Address.h>
#include <Domain/ExecutionConfig.h>
#include <zmq.hpp>
#include "Domain/TeamType.h"
#include "Domain/Debug.h"

namespace vss {

    class IDebugSender {
    public:
        virtual void createSocket(ExecutionConfig&) = 0;
        virtual void createSocket(Address) = 0;
        virtual void createSocket(TeamType) = 0;
        virtual void closeSocket() = 0;
        virtual void sendDebug(Debug) = 0;

        virtual ~IDebugSender();

    protected:
        zmq::context_t *context;
        zmq::socket_t *socket;
        Address address;
    };

    IDebugSender::~IDebugSender() {
        socket->close();
        delete socket;
        delete context;
    }

}

#endif //VSS_CORE_IDEBUGSENDER_H
