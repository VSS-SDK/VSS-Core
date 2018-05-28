//
// Created by johnathan on 28/05/18.
//

#include <CommandReceiver.h>
#include <command.pb.h>
#include <Helpers/CommandMapper.h>

namespace vss{
    CommandReceiver::CommandReceiver() {
        address = "";
    }

    void CommandReceiver::createSocket(TeamType teamType) {
        SetupAddress(teamType);

        context = new zmq::context_t( 1 );
        socket = new zmq::socket_t( *context, ZMQ_PAIR );

        std::cout << "Connecting Server Receiver Team 1: " << address << std::endl;
        socket->bind( address.c_str());
    }

    Command CommandReceiver::receiveCommand() {
        vss_command::Global_Commands globalCommands;
        zmq::message_t request;
        socket->recv( &request );

        std::string msg_str( static_cast<char*>(request.data()), request.size());
        globalCommands.ParseFromString( msg_str );

        return CommandMapper::globalCommandsToCommand(globalCommands);
    }

    void CommandReceiver::SetupAddress(TeamType teamType) {
        if(teamType == TeamType::Yellow)
            address = "tcp://*:5556";
        else
            address = "tcp://*:5557";
    }


}