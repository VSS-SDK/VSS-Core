//
// Created by johnathan on 27/05/18.
//

#ifndef VSS_CORE_ICONTROLRECEIVER_H
#define VSS_CORE_ICONTROLRECEIVER_H

#include "Domain/Control.h"

namespace vss {
    class IControlReceiver {
    public:
        virtual void createSocket() = 0;
        virtual Control receiveControl() = 0;
        virtual void setAddress(std::string) = 0;
    };
}

#endif //VSS_CORE_ICONTROLRECEIVER_H
