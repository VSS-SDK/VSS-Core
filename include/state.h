#ifndef _STATE_H_
#define _STATE_H_

#include "ball.h"
#include "robot.h"
#include <vector>
#include <string>

class State {

private:
    std::vector<Robot> team_blue;
    std::vector<Robot> team_yellow;
    Ball ball;

public:
    State();
    State(vss_state::Global_State global_state, std::string main_color);
    void globalStateToState(vss_state::Global_State, std::string);
    void spinField180Degrees();
};
 
#endif