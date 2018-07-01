//
// Created by johnathan on 27/05/18.
//

#include <Helpers/CommandMapper.h>
#include <Domain/Constants.h>
#include "Communications/CommandSender.h"

namespace vss{

    CommandSender::CommandSender(){
        address = Address();
    }

    void CommandSender::createSocket(Address address) {
        this->address = address;
        context = new zmq::context_t(1);
        socket = new zmq::socket_t(*context, ZMQ_PAIR);

        std::cout << "Command Sender Connected: " << this->address << std::endl;
        socket->bind(this->address.getFullAddress().c_str());
    }

    void CommandSender::createSocket(TeamType teamType) {
        SetupAddress(teamType);

        context = new zmq::context_t(1);
        socket = new zmq::socket_t(*context, ZMQ_PAIR);

        std::cout << "Command Receiver Connected: " << address << std::endl;
        socket->bind(address.getFullAddress().c_str());
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
        if(teamType == TeamType::Yellow){
            address = Address(DEFAULT_COMMAND_SEND_ADDRESS, DEFAULT_COMMAND_YELLOW_PORT);
            std::cout << "Yellow Team Sender Connected: " << address.getFullAddress() << std::endl;
        }else{
            address = Address(DEFAULT_COMMAND_SEND_ADDRESS, DEFAULT_COMMAND_BLUE_PORT);
            std::cout << "Blue Team Sender Connected: " << address.getFullAddress() << std::endl;
        }
    }

}
