//
// Created by johnathan on 28/05/18.
//

#include <Communications/CommandReceiver.h>
#include <Helpers/CommandMapper.h>
#include <Domain/Constants.h>

namespace vss{

    CommandReceiver::CommandReceiver() {
        address = Address();
    }

    void CommandReceiver::createSocket(Address address) {
        this->address = address;
        context = new zmq::context_t( 1 );
        socket = new zmq::socket_t( *context, ZMQ_PAIR );

        std::cout << "Command Receiver Connected: " << this->address << std::endl;
        socket->bind(this->address.getFullAddress().c_str());
    }

    void CommandReceiver::createSocket(TeamType teamType) {
        SetupAddress(teamType);

        context = new zmq::context_t( 1 );
        socket = new zmq::socket_t( *context, ZMQ_PAIR );

        std::cout << "Command Receiver Connected: " << address << std::endl;
        socket->bind(address.getFullAddress().c_str());
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
        if(teamType == TeamType::Yellow){
            address = Address(DEFAULT_COMMAND_RECEIVE_ADDRESS, DEFAULT_COMMAND_YELLOW_PORT);
            std::cout << "Yellow Team Receiver Connected: " << address.getFullAddress() << std::endl;
        }else{
            address = Address(DEFAULT_COMMAND_RECEIVE_ADDRESS, DEFAULT_COMMAND_BLUE_PORT);
            std::cout << "Blue Team Receiver Connected: " << address.getFullAddress() << std::endl;
        }
    }

}