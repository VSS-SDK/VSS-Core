#ifndef _ROBOT_H_
#define _ROBOT_H_

#include "Pose.h"

namespace vss {

    class Robot : public Pose {
    public:
        Robot();
        Robot(float x, float y, float angle, float speedX, float speedY, float speedAngle);

        friend std::ostream& operator<<(std::ostream& os, const Robot& robot);

        float speedX;
        float speedY;
        float speedAngle;
    };

}

#endif