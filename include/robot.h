#ifndef _ROBOT_H_
#define _ROBOT_H_

#include "object.h"
#include "state.pb.h"

class Robot : public Object {

private:
    float m_angle;
    float m_speed_angle;

public:
    Robot();
    Robot(vss_state::Robot_State);
    void robotStateToRobot(vss_state::Robot_State);
};
 
#endif