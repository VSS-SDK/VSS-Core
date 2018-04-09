#include "object.h"

Object::Object() {}

void Object::spinField180Degrees(){

    // 170 is the size in x of the field
    x = 170 - x;

    // 130 is the size in y of the field    
    y = 130 - y;
    
    if (angle + 180 > 360){
        angle = angle - 180;
    } else {
        angle = angle + 180;
    }
}

float Object::radian_angle(){
    return (2 * M_PI * angle) / 360;
}

float Object::speed_radian_angle(){
    return (2 * M_PI * speed_angle) / 360;
}