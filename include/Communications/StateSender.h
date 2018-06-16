//
// Created by johnathan on 27/05/18.
//

#ifndef VSS_CORE_STATESENDER_H
#define VSS_CORE_STATESENDER_H

#include <Interfaces/IStateSender.h>
#include <zmq.hpp>

namespace vss{

    class StateSender : public IStateSender {
    public:
        StateSender();

        void createSocket() override;
        void sendState(State) override;
        void setAddress(std::string) override;

    protected:
        zmq::context_t *context;
        zmq::socket_t *socket;
        
        std::string address;
    };

}

#endif //VSS_CORE_STATESENDER_H
