#ifndef _ROBOT_H_
#define _ROBOT_H_

#include <cmath>
#include "state.pb.h"

class Robot {

private:
    float m_x;
    float m_y;
    float m_angle;

    float m_speed_x;
    float m_speed_y;
    float m_speed_angle;

    void globalState2Robot();

protected:
    vss_state::Robot_State robot_state;


public:
    Robot(vss_state::Robot_State);

    float x();
    float y();
    float angle();
    float radian_angle();
};
 
#endif