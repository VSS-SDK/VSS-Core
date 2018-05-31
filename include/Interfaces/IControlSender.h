//
// Created by johnathan on 27/05/18.
//

#ifndef VSS_CORE_ICONTROLSENDER_H
#define VSS_CORE_ICONTROLSENDER_H

#include "Domain/Control.h"

namespace vss {

    class IControlSender {
    public:
        virtual void createSocket() = 0;
        virtual void sendControl(Control) = 0;
        virtual void setAddress(std::string) = 0;
    };

}

#endif //VSS_CORE_ICONTROLSENDER_H
