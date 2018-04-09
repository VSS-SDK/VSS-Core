#include "state.h"

State::State() {}

State::State(vss_state::Global_State global_state, std::string main_color) {
    globalStateToState(global_state, main_color);
    
    //if (spin){
    //    spinField180Degrees();
    //}
}

void State::globalStateToState(vss_state::Global_State global_state, std::string main_color) {

    ball = Ball(global_state.balls(0));

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

void State::spinField180Degrees(){

    ball.spinField180Degrees();

    for (int i = 0; i < 3; i++) {
        team_1[i].spinField180Degrees();
        team_2[i].spinField180Degrees();
    }
}