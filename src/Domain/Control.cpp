//
// Created by johnathan on 31/05/18.
//

#include <Domain/Control.h>

namespace vss {

    Control::Control() {
        paused = false;
    }

    Control::Control(bool paused, Ball ball, std::vector<Robot> teamYellow, std::vector<Robot> teamBlue) {
        this->paused = paused;
        this->ball = ball;
        this->teamYellow = teamYellow;
        this->teamBlue = teamBlue;
    }

    std::ostream &operator<<(std::ostream &os, const Control &control) {
        return os;
    }

}
