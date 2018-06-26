//
// Created by johnathan on 25/06/18.
//

#include <Communications/CommunicationBase.h>

namespace vss {

    void CommunicationBase::createSocket(Address address) {
        this->address = address;

        context = new zmq::context_t( 1 );
        socket = new zmq::socket_t( *context, ZMQ_PAIR );

        socket->bind(address.getFullAddress().c_str());
    }

}