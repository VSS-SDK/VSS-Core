//
// Created by johnathan on 28/05/18.
//

#ifndef VSS_CORE_COMMANDRECEIVER_H
#define VSS_CORE_COMMANDRECEIVER_H

#include <Interfaces/ICommandReceiver.h>
#include <zmq.hpp>
#include "Communications/CommunicationBase.h"

namespace vss {

    class CommandReceiver : public ICommandReceiver, public CommunicationBase {
    public:
        CommandReceiver();

        void createSocket(TeamType) override;
        Command receiveCommand() override;

    protected:
        void SetupAddress(TeamType);
    };

}

#endif //VSS_CORE_COMMANDRECEIVER_H
