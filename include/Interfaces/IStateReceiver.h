//
// Created by johnathan on 27/05/18.
//

#ifndef VSS_CORE_ISTATERECEIVER_H
#define VSS_CORE_ISTATERECEIVER_H

#include "Domain/State.h"

namespace vss {
    class IStateReceiver {
    public:
        virtual void createSocket() = 0;
        virtual State receiveState(FieldTransformationType) = 0;
        virtual void setAddress(std::string) = 0;
    };
}

#endif //VSS_CORE_ISTATERECEIVER_H