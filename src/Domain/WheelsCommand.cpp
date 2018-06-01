//
// Created by johnathan on 27/05/18.
//

#include "Domain/WheelsCommand.h"

namespace vss{
    WheelsCommand::WheelsCommand(){
        id = 0;
        leftVel = 0;
        rightVel = 0;
    }

    WheelsCommand::WheelsCommand(int id, float leftVel, float rightVel) {
        this->id = id;
        this->leftVel = leftVel;
        this->rightVel = rightVel;
    }

    std::ostream &operator<<(std::ostream &os, const WheelsCommand &wheelsCommand) {
        return os << "WheelsCommand(" << wheelsCommand.id << ", " << wheelsCommand.leftVel << ", " << wheelsCommand.rightVel << ")";;
    }
}

