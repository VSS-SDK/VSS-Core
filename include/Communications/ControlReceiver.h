//
// Created by johnathan on 31/05/18.
//

#ifndef VSS_CORE_CONTROLRECEIVER_H
#define VSS_CORE_CONTROLRECEIVER_H

#include <Interfaces/IControlReceiver.h>
#include <zmq.hpp>
#include "Communications/CommunicationBase.h"

namespace vss {

    class ControlReceiver : public IControlReceiver, public CommunicationBase {
    public:
        ControlReceiver();

        void createSocket() override;
        Control receiveControl() override;
        void setAddress(std::string) override;
    };

}

#endif //VSS_CORE_CONTROLRECEIVER_H
