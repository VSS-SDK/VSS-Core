//
// Created by johnathan on 30/05/18.
//

#include <Domain/Pose.h>

namespace vss {

    Pose::Pose() {
        x = 0;
        y = 0;
        angle = 0;
    }

    Pose::Pose(float x, float y, float angle) {
        this->x = x;
        this->y = y;
        this->angle = angle;
    }

    std::ostream &operator<<(std::ostream &os, const Pose &pose) {
        return os << "Pose(" << pose.x << ", " << pose.y << ", " << pose.angle << ")";
    }

}

