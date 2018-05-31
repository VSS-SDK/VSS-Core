//
// Created by johnathan on 27/05/18.
//

#include <Helpers/CommandMapper.h>
#include "Communications/CommandSender.h"

namespace vss{

    CommandSender::CommandSender(){
        address = "";
    }

    void CommandSender::createSocket(TeamType teamType) {
        SetupAddress(teamType);

        context = new zmq::context_t(1);
        socket = new zmq::socket_t(*context, ZMQ_PAIR);

        std::cout << "Connecting Client Sender Team 1: " << address << " (yellow team)" << std::endl << std::endl;
        socket->connect(address.c_str());
    }

    void CommandSender::sendCommand(Command command) {
        auto globalCommands = CommandMapper::commandToGlobalCommands(command);

        std::string msg_str;
        globalCommands.SerializeToString( &msg_str );

        zmq::message_t request ( msg_str.size());
        memcpy ((void *) request.data (), msg_str.c_str(), msg_str.size());
        socket->send( request );
    }

    void CommandSender::SetupAddress(TeamType teamType) {
        if(teamType == TeamType::Yellow)
            address = "tcp://localhost:5556";
        else
            address = "tcp://localhost:5557";
    }

}
