//
// Created by johnathan on 23/06/18.
//

#ifndef VSS_CORE_COMMUNICATIONBASE_H
#define VSS_CORE_COMMUNICATIONBASE_H

#include <zmq.hpp>
#include <Domain/TeamType.h>

namespace vss {

    class CommunicationBase {
    public:
        zmq::context_t *context;
        zmq::socket_t *socket;
        std::string address;
    };

}

#endif //VSS_CORE_INTERFACEBASE_H
