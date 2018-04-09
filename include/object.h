#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <cmath>
#include "state.pb.h"

class Object {

protected:
    float m_x;
    float m_y;
    float m_angle;
    float m_speed_x;
    float m_speed_y;
    float m_speed_angle;

public:
    Object();
    void spinField180Degrees();

    float x();
    float y();
    float angle();
    float radian_angle();
};

#endif