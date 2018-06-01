#include "Domain/Ball.h"

namespace vss{
    Ball::Ball() {
        x = 0;
        y = 0;
        speedX = 0;
        speedY = 0;
    }

    Ball::Ball(float x, float y, float speedX, float speedY) {
        this->x = x;
        this->y = y;
        this->speedX = speedX;
        this->speedY = speedY;
    }

    std::ostream &operator<<(std::ostream &os, const Ball &ball) {
        return os << "Ball(" << ball.x << ", " << ball.y << ", " << ball.speedX << ", " << ball.speedY << ")";
    }
}