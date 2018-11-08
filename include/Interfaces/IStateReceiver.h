//
// Created by johnathan on 27/05/18.
//

#ifndef VSS_CORE_ISTATERECEIVER_H
#define VSS_CORE_ISTATERECEIVER_H

#include <Domain/Address.h>
#include <Domain/ExecutionConfig.h>
#include <zmq.hpp>
#include "Domain/State.h"
#include "Domain/FieldTransformationType.h"

namespace vss {

    class IStateReceiver {
    public:
        virtual void createSocket(ExecutionConfig&) = 0;
        virtual void createSocket(Address) = 0;
        virtual void createSocket() = 0;
        virtual void closeSocket() = 0;
        virtual State receiveState(FieldTransformationType) = 0;

        virtual ~IStateReceiver();

    protected:
        zmq::context_t *context;
        zmq::socket_t *socket;
        Address address;
    };

    IStateReceiver::~IStateReceiver() {
        socket->close();
        delete socket;
        delete context;
    }

}

#endif //VSS_CORE_ISTATERECEIVER_H