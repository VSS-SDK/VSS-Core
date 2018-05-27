#include "Domain/State.h"

namespace vss {
    class IStateReceiver {
    public:
        virtual void createSocketReceiveState(std::string addr_client_multicast = "tcp://localhost:5555") = 0;
        virtual State receiveState(FieldTransformation) = 0;
    };
}