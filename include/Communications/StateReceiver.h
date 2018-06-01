/*
 * This file is part of the VSS-SDK project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#ifndef _INTERFACE_CORE_H_
#define _INTERFACE_CORE_H_

#include "sstream"
#include <iostream>
#include <string>
#include "unistd.h"

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

    class StateReceiver : public IStateReceiver {
    public:
        StateReceiver();

        void createSocket() override;
        void setAddress(std::string) override;
        State receiveState(FieldTransformationType) override;

    protected:
        zmq::context_t *context;
        zmq::socket_t *socket;

        std::string address;
    };

}

#endif // _INTERFACE_CORE_H_
