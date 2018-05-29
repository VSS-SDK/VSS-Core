//
// Created by johnathan on 29/05/18.
//

#include <iostream>
#include <debug.pb.h>
#include "DebugSender.h"

namespace vss {

    DebugSender::DebugSender() {
        address = "";
    }

    void DebugSender::createSocket(TeamType teamType) {
        SetupAddress(teamType);

        context = new zmq::context_t( 1 );
        socket = new zmq::socket_t( *context, ZMQ_PAIR );

        std::cout << "Connecting Server Sender Debug Team 1: " << address << "(yellow team)" << std::endl << std::endl;
        socket->connect( address.c_str());
    }

    void DebugSender::sendDebug(Debug debug) {
        vss_debug::Global_Debug globalDebug;

        std::string msg_str;
        globalDebug.SerializeToString( &msg_str );

        zmq::message_t request ( msg_str.size());
        memcpy ((void *) request.data (), msg_str.c_str(), msg_str.size());
        socket->send( request );
    }

    void DebugSender::SetupAddress(TeamType teamType) {
        if(teamType == TeamType::Yellow)
            address = "tcp://localhost:5558";
        else
            address = "tcp://localhost:5559";
    }

}