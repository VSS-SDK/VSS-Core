//
// Created by johnathan on 27/05/18.
//

#ifndef VSS_CORE_ICONTROLRECEIVER_H
#define VSS_CORE_ICONTROLRECEIVER_H

#include <Domain/Address.h>
#include <Domain/ExecutionConfig.h>
#include <zmq.hpp>
#include "Domain/Control.h"

namespace vss {

    class IControlReceiver {
    public:
        virtual void createSocket(ExecutionConfig&) = 0;
        virtual void createSocket(Address) = 0;
        virtual void createSocket() = 0;
        virtual void closeSocket() = 0;
        virtual Control receiveControl() = 0;

        virtual ~IControlReceiver();

    protected:
        zmq::context_t *context;
        zmq::socket_t *socket;
        Address address;
    };

    IControlReceiver::~IControlReceiver() {
        socket->close();
        delete socket;
        delete context;
    }

}

#endif //VSS_CORE_ICONTROLRECEIVER_H
