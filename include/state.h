#ifndef _STATE_H_
#define _STATE_H_

#include "ball.h"
#include "robot.h"
#include <vector>
#include <string>

class State {

private:
    std::vector<Robot> team_1;
    std::vector<Robot> team_2;
    Ball ball;
    
protected:

public:
    State();
    void globalStateToState(vss_state::Global_State, std::string);
};
 
#endif