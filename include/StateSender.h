//
// Created by johnathan on 27/05/18.
//

#ifndef VSS_CORE_STATESENDER_H
#define VSS_CORE_STATESENDER_H

#include "Interfaces/IStateSender.h"
#include "Domain/State.h"

#include "Domain/State.h"
#include "Domain/FieldTransformationType.h"
#include "Helpers/CoordinateTransformer.h"
#include "Interfaces/IStateReceiver.h"

#include "zmq.hpp"       //! ZMQ: utilizado para comunicação via Sockets
#include <google/protobuf/text_format.h> //! Protobuf: utilizado para serialização/deserialização das mensagens
#include "state.pb.h"      //! Protobuf: pacote gerado pelo state.proto
#include "command.pb.h"      //! Protobuf: pacote gerado pelo command.proto
#include "debug.pb.h"      //! Protobuf: pacote gerado pelo debug.proto
#include "control.pb.h"      //! Protobuf: pacote gerado pelo debug.proto

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
