//
// Created by johnathan on 27/05/18.
//

#ifndef VSS_CORE_IDEBUGRECEIVER_H
#define VSS_CORE_IDEBUGRECEIVER_H

#include <string>
#include "Domain/Debug.h"

namespace vss {
    class IDebugReceiver {
    public:
        virtual void createSocket() = 0;
        virtual Debug receiveState() = 0;
        virtual void setAddress(std::string) = 0;
    };
}

#endif //VSS_CORE_IDEBUGRECEIVER_H
