//
// Created by johnathan on 31/05/18.
//

#include <Communications/ControlSender.h>
#include <Helpers/ControlMapper.h>

namespace vss {

    ControlSender::ControlSender() {
        address = "tcp://*:5560";
    }

    void ControlSender::createSocket() {
        context = new zmq::context_t( 1 );
        socket = new zmq::socket_t( *context, ZMQ_PUB );

        std::cout << "Connecting Server Multicast Sender: " << address << std::endl;
        socket->bind( address.c_str());
    }

    void ControlSender::sendControl(Control control) {
        auto userControl = vss::ControlMapper::controlToUserControl(control);
        std::string msg_str;
        userControl.SerializeToString( &msg_str );

        zmq::message_t request ( msg_str.size());
        memcpy ((void *) request.data (), msg_str.c_str(), msg_str.size());

        socket->send( request );
    }

    void ControlSender::setAddress(std::string address) {
        this->address = address;
    }

}