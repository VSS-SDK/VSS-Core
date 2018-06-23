//
// Created by johnathan on 31/05/18.
//

#ifndef VSS_CORE_CONTROLSENDER_H
#define VSS_CORE_CONTROLSENDER_H

#include <Interfaces/IControlSender.h>
#include <zmq.hpp>
#include "Communications/CommunicationBase.h"

namespace vss {

    class ControlSender : public IControlSender, public CommunicationBase {
    public:
        ControlSender();

        void createSocket() override;
        void sendControl(Control) override;
        void setAddress(std::string) override;
    };

}

#endif //VSS_CORE_CONTROLSENDER_H
