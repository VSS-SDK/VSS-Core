//
// Created by johnathan on 27/05/18.
//

#ifndef VSS_CORE_ICONTROLSENDER_H
#define VSS_CORE_ICONTROLSENDER_H

#include <Domain/Address.h>
#include <Domain/ExecutionConfig.h>
#include <zmq.hpp>
#include "Domain/Control.h"

namespace vss {

    class IControlSender {
    public:
        virtual void createSocket(ExecutionConfig&) = 0;
        virtual void createSocket(Address) = 0;
        virtual void createSocket() = 0;
        virtual void closeSocket() = 0;
        virtual void sendControl(Control) = 0;

        virtual ~IControlSender();

    protected:
        zmq::context_t *context;
        zmq::socket_t *socket;
        Address address;
    };

    IControlSender::~IControlSender() {
        socket->close();
        delete socket;
        delete context;
    }

}

#endif //VSS_CORE_ICONTROLSENDER_H
