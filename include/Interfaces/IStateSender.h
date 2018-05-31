//
// Created by johnathan on 27/05/18.
//

#ifndef VSS_CORE_ISTATESENDER_H
#define VSS_CORE_ISTATESENDER_H

#include "iostream"
#include "Domain/State.h"

namespace vss {

    class IStateSender {
    public:
        virtual void createSocket() = 0;
        virtual void sendState(State) = 0;
        virtual void setAddress(std::string) = 0;
    };

}

#endif //VSS_CORE_ISTATESENDER_H
