//
// Created by johnathan on 27/05/18.
//

#include "StateSender.h"

namespace vss{
    StateSender::StateSender(){

    }

    void StateSender::createSocketSendState(std::string addr_server_multicast){
        this->addr_client_multicast = addr_server_multicast;

        context = new zmq::context_t( 1 );
        socket = new zmq::socket_t( *context, ZMQ_PUB );

        std::cout << "Connecting Server Multicast Sender: " << addr_server_multicast << std::endl;
        socket->bind( addr_server_multicast.c_str());
    }

    void StateSender::sendState(State state){
        std::string msg_str;
        globalState.SerializeToString( &msg_str );

        zmq::message_t request ( msg_str.size());
        memcpy ((void *) request.data (), msg_str.c_str(), msg_str.size());

        socket->send( request );
    }
}