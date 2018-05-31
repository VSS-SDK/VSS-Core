#include "Domain/Robot.h"

namespace vss{

    Robot::Robot() {
        x = 0;
        y = 0;
        angle = 0;
        speedX = 0;
        speedY = 0;
        speedAngle = 0;
    }

    Robot::Robot(float x, float y, float angle, float speedX, float speedY, float speedAngle) {
        this->x = x;
        this->y = y;
        this->angle = angle;
        this->speedX = speedX;
        this->speedY = speedY;
        this->speedAngle = speedAngle;
    }

    std::ostream &operator<<(std::ostream &os, const Robot &robot) {
        return os << "Robot(" << robot.x << ", " << robot.y << ", " << robot.angle << "," << robot.speedX << ", " << robot.speedY << ", " << robot.speedAngle << ")";
    }

}