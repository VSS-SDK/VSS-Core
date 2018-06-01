//
// Created by johnathan on 31/05/18.
//

#include <Communications/DebugReceiver.h>
#include <debug.pb.h>
#include <Helpers/DebugMapper.h>

namespace vss {

    DebugReceiver::DebugReceiver() {
        address = "";
    }

    void DebugReceiver::createSocket(TeamType teamType) {
        SetupAddress(teamType);

        context = new zmq::context_t( 1 );
        socket = new zmq::socket_t( *context, ZMQ_PAIR );

        std::cout << "Connecting Client Receiver Debug Team 1: " << address << std::endl;
        socket->bind( address.c_str());
    }

    Debug DebugReceiver::receiveDebug() {
        vss_debug::Global_Debug globalDebug;

        zmq::message_t request;
        socket->recv( &request );

        std::string msg_str( static_cast<char*>(request.data()), request.size());
        globalDebug.ParseFromString( msg_str );

        return DebugMapper::globalDebugToDebug(globalDebug);
    }

    void DebugReceiver::SetupAddress(TeamType teamType) {
        if(teamType == TeamType::Yellow)
            address = "tcp://*:5558";
        else
            address = "tcp://*:5559";
    }
}