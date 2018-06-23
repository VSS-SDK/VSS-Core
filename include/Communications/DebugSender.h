//
// Created by johnathan on 29/05/18.
//

#ifndef VSS_CORE_DEBUGSENDER_H
#define VSS_CORE_DEBUGSENDER_H

#include <Interfaces/IDebugSender.h>
#include <zmq.hpp>
#include "Communications/CommunicationBase.h"

namespace vss {

    class DebugSender : public IDebugSender, public CommunicationBase {
    public:
        DebugSender();

        void createSocket(TeamType) override;
        void sendDebug(Debug) override;

    protected:
        void SetupAddress(TeamType);
    };

}

#endif //VSS_CORE_DEBUGSENDER_H
