//
// Created by johnathan on 31/05/18.
//

#ifndef VSS_CORE_CONTROLSENDER_H
#define VSS_CORE_CONTROLSENDER_H

#include <Interfaces/IControlSender.h>
#include <zmq.hpp>

namespace vss {

    class ControlSender : public IControlSender {
    public:
        ControlSender();

        void createSocket() override;
        void sendControl(Control) override;
        void setAddress(std::string) override;

    protected:
        zmq::context_t *context;
        zmq::socket_t *socket;
        std::string address;
    };

}

#endif //VSS_CORE_CONTROLSENDER_H
