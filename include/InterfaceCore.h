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

#include "State.h"
#include "FieldTransformation.h"
#include "CoordinateTransformer.h"

#include "zmq.hpp"       //! ZMQ: utilizado para comunicação via Sockets
#include <google/protobuf/text_format.h> //! Protobuf: utilizado para serialização/deserialização das mensagens
#include "state.pb.h"      //! Protobuf: pacote gerado pelo state.proto
#include "command.pb.h"      //! Protobuf: pacote gerado pelo command.proto
#include "debug.pb.h"      //! Protobuf: pacote gerado pelo debug.proto
#include "control.pb.h"      //! Protobuf: pacote gerado pelo debug.proto

namespace vss{

    class InterfaceCore {
    public:
        InterfaceCore();

        void createSocketReceiveState( std::string addr_client_multicast = "tcp://localhost:5555" );
        State receiveState(FieldTransformation);

        Ball ballStateToBall(vss_state::Ball_State);
        Robot robotStateToRobot(vss_state::Robot_State);
        State globalStateToState(vss_state::Global_State, FieldTransformation);

    protected:

        zmq::context_t *context;
        zmq::socket_t *socket;

        vss_state::Global_State globalState;

        std::string addr_client_multicast;
    };

}

#endif // _INTERFACE_CORE_H_
