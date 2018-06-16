//
// Created by johnathan on 27/05/18.
//

#ifndef VSS_CORE_ICOMMANDRECEIVER_H
#define VSS_CORE_ICOMMANDRECEIVER_H

#include <Domain/TeamType.h>
#include "Domain/Command.h"

namespace vss {

    class ICommandReceiver {
    public:
        virtual void createSocket(TeamType) = 0;
        virtual Command receiveCommand() = 0;
    };

}

#endif //VSS_CORE_ICOMMANDRECEIVER_H
