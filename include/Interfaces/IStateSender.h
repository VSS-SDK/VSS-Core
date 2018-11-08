//
// Created by johnathan on 27/05/18.
//

#ifndef VSS_CORE_ISTATESENDER_H
#define VSS_CORE_ISTATESENDER_H

#include <Domain/Address.h>
#include <Domain/ExecutionConfig.h>
#include "Domain/State.h"
#include "iostream"
#include <zmq.hpp>

namespace vss {

    class IStateSender {
    public:
        virtual void createSocket(ExecutionConfig&) = 0;
        virtual void createSocket(Address) = 0;
        virtual void createSocket() = 0;
        virtual void closeSocket() = 0;
        virtual void sendState(State) = 0;

        virtual ~IStateSender();

    protected:
        zmq::context_t *context;
        zmq::socket_t *socket;
        Address address;

    };

    IStateSender::~IStateSender() {
        socket->close();
        delete socket;
        delete context;
    }

}

#endif //VSS_CORE_ISTATESENDER_H
