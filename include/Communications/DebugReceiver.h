//
// Created by johnathan on 31/05/18.
//

#ifndef VSS_CORE_DEBUGRECEIVER_H
#define VSS_CORE_DEBUGRECEIVER_H


#include <Interfaces/IDebugReceiver.h>
#include <Domain/TeamType.h>
#include <zmq.hpp>

namespace vss {

    class DebugReceiver : public IDebugReceiver {
    public:
        DebugReceiver();

        void createSocket(TeamType) override;
        Debug receiveDebug() override;

    protected:
        zmq::context_t *context;
        zmq::socket_t *socket;
        std::string address;

        void SetupAddress(TeamType);
    };

}

#endif //VSS_CORE_DEBUGRECEIVER_H
