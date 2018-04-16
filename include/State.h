#ifndef _STATE_H_
#define _STATE_H_

#include "Ball.h"
#include "Robot.h"
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