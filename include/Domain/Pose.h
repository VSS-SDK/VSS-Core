//
// Created by johnathan on 30/05/18.
//

#ifndef VSS_CORE_POSE_H
#define VSS_CORE_POSE_H

#include "Point.h"

namespace vss {

    class Pose : public Point {
    public:
        Pose();
        Pose(float x, float y, float angle);

        friend std::ostream& operator<<(std::ostream& os, const Pose& pose);

        float angle;
    };

}

#endif //VSS_CORE_POSE_H
