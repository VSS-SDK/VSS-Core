#include "Domain/State.h"

namespace vss{
    State::State() {
        teamBlue.resize(3);
        teamYellow.resize(3);
    }

    State::State(Ball ball, std::vector<Robot> teamBlue, std::vector<Robot> teamYellow) {
        this->ball = ball;
        this->teamBlue = teamBlue;
        this->teamYellow = teamYellow;
    }

    std::ostream &operator<<(std::ostream &os, const State &state) {
        os << "State {" << std::endl;

        os << "\t" << state.ball << std::endl << std::endl;
        os << "\tTeamYellow" << std::endl;

        for(unsigned int i = 0 ; i < state.teamYellow.size() ; i++){
            os << "\t" << state.teamYellow[i] << std::endl;
        }

        os << std::endl << "\tTeamBlue" << std::endl;

        for(unsigned int i = 0 ; i < state.teamYellow.size() ; i++){
            os << "\t" << state.teamYellow[i] << std::endl;
        }

        os << "}";

        return os;
    }
}