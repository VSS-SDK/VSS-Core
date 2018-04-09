#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <cmath>
#include "state.pb.h"

class Object {

protected:
    float x;
    float y;
    float angle;
    
    float speed_x;
    float speed_y;
    float speed_angle;

public:
    Object();

    void spinField180Degrees();
    float radian_angle();
    float speed_radian_angle();
};

#endif