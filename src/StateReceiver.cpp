/*
 * This file is part of the VSS-SDK project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#include "StateReceiver.h"
#include "Helpers/StateMapper.h"

namespace vss{
    StateReceiver::StateReceiver(){
    }

    void StateReceiver::createSocketReceiveState(std::string addr_client_multicast){
      this->addr_client_multicast = addr_client_multicast;

      context = new zmq::context_t( 1 );
      socket = new zmq::socket_t( *context, ZMQ_SUB );

      std::cout << "Connecting Client Multicast Receiver: " << addr_client_multicast << std::endl;
      socket->connect( addr_client_multicast.c_str());

      socket->setsockopt( ZMQ_SUBSCRIBE, "", 0 );
    }

    State StateReceiver::receiveState(FieldTransformation userTransformation){
      zmq::message_t request;
      socket->recv(&request, 0);
      std::string msg_str( static_cast<char*>(request.data()), request.size());
      globalState.ParseFromString(msg_str);

      auto state = StateMapper::globalStateToState(globalState);

      if (userTransformation == FieldTransformation::Flip180Degrees) {
        state = CoordinateTransformer::spinField180Degrees(state);
      }

      return state;
    }
}