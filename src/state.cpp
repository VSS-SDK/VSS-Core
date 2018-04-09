#include "state.h"

State::State() {}

State::State(vss_state::Global_State global_state) {
    globalStateToState(global_state);
    
    // chamar caso o usuario queira os dados rotacionados
    // spinField180Degrees();
}

void State::globalStateToState(vss_state::Global_State global_state) {
    ball = Ball(global_state.balls(0));
    team_blue = Robot(global_state.robots_blue(i));
    team_yellow = Robot(global_state.robots_yellow(i));
}

void State::spinField180Degrees(){
    ball.spinField180Degrees();

    for (int i = 0; i < 3; i++) {
        team_1[i].spinField180Degrees();
        team_2[i].spinField180Degrees();
    }
}