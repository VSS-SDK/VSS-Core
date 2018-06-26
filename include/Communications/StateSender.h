//
// Created by johnathan on 27/05/18.
//

#ifndef VSS_CORE_STATESENDER_H
#define VSS_CORE_STATESENDER_H

#include <Interfaces/IStateSender.h>
#include <zmq.hpp>
#include "Communications/CommunicationBase.h"

namespace vss{

    class StateSender : public IStateSender, public CommunicationBase {
    public:
        StateSender();

        void createSocket() override;
        void sendState(State) override;
    };

}

#endif //VSS_CORE_STATESENDER_H
