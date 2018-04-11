#ifndef STATE_TRANSFORMATION_H_
#define STATE_TRANSFORMATION_H_

#include "Ball.h"
#include "Robot.h"
#include "state.pb.h"

class StateTransformation {

public:
    static Ball ballStateToBall(vss_state::Ball_State);
    static Robot robotStateToRobot(vss_state::Robot_State);
};
 
#endif