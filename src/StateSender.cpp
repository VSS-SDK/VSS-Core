//
// Created by johnathan on 27/05/18.
//

#include <Helpers/StateMapper.h>
#include "StateSender.h"

namespace vss{
    StateSender::StateSender(){
        address = "tcp://*:5555";
    }

    void StateSender::createSocket(){
        context = new zmq::context_t( 1 );
        socket = new zmq::socket_t( *context, ZMQ_PUB );

        std::cout << "Connecting Server Multicast Sender: " << address << std::endl;
        socket->bind( address.c_str());
    }

    void StateSender::sendState(State state){
        std::string msg_str;
        vss_state::Global_State globalState;

        globalState = StateMapper::stateToGlobalState(state);
        globalState.SerializeToString( &msg_str );

        zmq::message_t request ( msg_str.size());
        memcpy ((void *) request.data (), msg_str.c_str(), msg_str.size());

        socket->send( request );
    }

    void StateSender::setAddress(std::string address) {
        this->address = address;
    }
}