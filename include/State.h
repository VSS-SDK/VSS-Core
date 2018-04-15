#ifndef _STATE_H_
#define _STATE_H_

#include "Ball.h"
#include "Robot.h"
#include <vector>

namespace vss {

    class State {
    public:
        State();

        vss::Ball ball;
        std::vector<vss::Robot> teamBlue;
        std::vector<vss::Robot> teamYellow;
    };

}
#endif