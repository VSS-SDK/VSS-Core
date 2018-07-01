//
// Created by johnathan on 27/05/18.
//

#include <Helpers/StateMapper.h>
#include <Domain/Constants.h>
#include "Communications/StateSender.h"

namespace vss{

    StateSender::StateSender(){
        address = Address(DEFAULT_STATE_SEND_ADDRESS, DEFAULT_STATE_PORT);
    }

    void StateSender::createSocket(Address address) {
        this->address = address;

        context = new zmq::context_t( 1 );
        socket = new zmq::socket_t( *context, ZMQ_PUB );

        std::cout << "State Sender Connected: " << this->address << std::endl;
        socket->bind(address.getFullAddress().c_str());
    }

    void StateSender::createSocket(){
        context = new zmq::context_t( 1 );
        socket = new zmq::socket_t( *context, ZMQ_PUB );

        std::cout << "State Sender Connected: " << address << std::endl;
        socket->bind(address.getFullAddress().c_str());
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

}