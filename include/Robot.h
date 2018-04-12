#ifndef _ROBOT_H_
#define _ROBOT_H_

namespace vss {

    class Robot {

    public:
        Robot();

        float x;
        float y;
        float angle;
        float speedX;
        float speedY;
        float speedAngle;
    };

} 
#endif