#ifndef _STATE_H_
#define _STATE_H_

#include "Domain/Ball.h"
#include "Domain/Robot.h"
#include <vector>

namespace vss {

    class State {
    public:
        State();

        Ball ball;
        std::vector<Robot> teamBlue;
        std::vector<Robot> teamYellow;
    };

}
#endif