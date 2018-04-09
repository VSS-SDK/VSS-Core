#include "state.h"

State::State() {}

void State::globalStateToState(vss_state::Global_State global_state, std::string main_color) {

    if (main_color == "yellow") {
        for (int i = 0; i < 3; i++) {
            team_1[i] = Robot(global_state.robots_yellow(i));
            team_2[i] = Robot(global_state.robots_blue(i));
        }
        
    } else if (main_color == "blue") {
        for (int i = 0; i < 3; i++) {
            team_1[i] = Robot(global_state.robots_blue(i));
            team_2[i] = Robot(global_state.robots_yellow(i));
        }
    }

}