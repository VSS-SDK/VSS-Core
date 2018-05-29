//
// Created by johnathan on 29/05/18.
//

#ifndef VSS_CORE_DEBUGSENDER_H
#define VSS_CORE_DEBUGSENDER_H

#include <Interfaces/IDebugSender.h>
#include <zmq.hpp>

namespace vss {
    class DebugSender : public IDebugSender {
    public:
        DebugSender();

        void createSocket(TeamType) override;
        void sendDebug(Debug) override;

    protected:
        zmq::context_t *context;
        zmq::socket_t *socket;
        std::string address;

        void SetupAddress(TeamType);
    };
}

#endif //VSS_CORE_DEBUGSENDER_H
