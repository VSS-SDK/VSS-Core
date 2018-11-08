//
// Created by johnathan on 27/05/18.
//

#ifndef VSS_CORE_IDEBUGRECEIVER_H
#define VSS_CORE_IDEBUGRECEIVER_H

#include <string>
#include <Domain/TeamType.h>
#include <Domain/Address.h>
#include <Domain/ExecutionConfig.h>
#include <zmq.hpp>
#include "Domain/Debug.h"

namespace vss {

    class IDebugReceiver {
    public:
        virtual void createSocket(ExecutionConfig&) = 0;
        virtual void createSocket(Address) = 0;
        virtual void createSocket(TeamType) = 0;
        virtual void closeSocket() = 0;
        virtual Debug receiveDebug() = 0;

        virtual ~IDebugReceiver();

    protected:
        zmq::context_t *context;
        zmq::socket_t *socket;
        Address address;
    };

    IDebugReceiver::~IDebugReceiver() {
        socket->close();
        delete socket;
        delete context;
    }

}

#endif //VSS_CORE_IDEBUGRECEIVER_H
