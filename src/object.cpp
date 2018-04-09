#include "object.h"

Object::Object() {}

float Object::x(){
    return m_x;
}

float Object::y(){
    return m_y;
}

float Object::angle(){
    return m_angle;
}

float Object::radian_angle(){
    return (2 * M_PI * m_angle) / 360;
}

void Object::spinField180Degrees(){
    m_x = 170 - m_x;
    m_y = 130 - m_y;
    
    if (m_angle + 180 > 360){
        m_angle = m_angle - 180;
    } else {
        m_angle = m_angle + 180;
    }
}