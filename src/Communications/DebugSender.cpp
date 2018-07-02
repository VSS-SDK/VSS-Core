//
// Created by johnathan on 29/05/18.
//

#include <iostream>
#include <Helpers/DebugMapper.h>
#include <Domain/Constants.h>
#include "Communications/DebugSender.h"

namespace vss {

    DebugSender::DebugSender() {
        address = Address();
    }

    void DebugSender::createSocket(Address address) {
        this->address = address;
        connect();
    }

    void DebugSender::createSocket(TeamType teamType) {
        setupAddress(teamType);
        connect();
    }

    void DebugSender::sendDebug(Debug debug) {
        std::string msg_str;
        auto globalDebug = DebugMapper::debugToGlobalDebug(debug);

        globalDebug.SerializeToString( &msg_str );

        zmq::message_t request ( msg_str.size());
        memcpy ((void *) request.data (), msg_str.c_str(), msg_str.size());
        socket->send( request );
    }

    void DebugSender::setupAddress(TeamType teamType) {
        if(teamType == TeamType::Yellow){
            address = Address(DEFAULT_DEBUG_SEND_ADDRESS, DEFAULT_DEBUG_YELLOW_PORT);
        }else{
            address = Address(DEFAULT_DEBUG_SEND_ADDRESS, DEFAULT_DEBUG_BLUE_PORT);
        }
    }

    void DebugSender::connect() {
        context = new zmq::context_t( 1 );
        socket = new zmq::socket_t( *context, ZMQ_PAIR );

        std::cout << "Debug Sender Connected: " << address << std::endl;
        socket->connect(address.getFullAddress().c_str());
    }

}