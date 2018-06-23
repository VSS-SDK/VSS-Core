//
// Created by johnathan on 31/05/18.
//

#ifndef VSS_CORE_DEBUGRECEIVER_H
#define VSS_CORE_DEBUGRECEIVER_H


#include <Interfaces/IDebugReceiver.h>
#include <Domain/TeamType.h>
#include <zmq.hpp>
#include "Communications/CommunicationBase.h"

namespace vss {

    class DebugReceiver : public IDebugReceiver, public CommunicationBase {
    public:
        DebugReceiver();

        void createSocket(TeamType) override;
        Debug receiveDebug() override;

    protected:
        void SetupAddress(TeamType);
    };

}

#endif //VSS_CORE_DEBUGRECEIVER_H
