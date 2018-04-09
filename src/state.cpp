#include "state.h"

State::State() {}

State::State(vss_state::Global_State global_state, int transformation) {
    globalStateToState(global_state, transformation);
}

void State::globalStateToState(vss_state::Global_State global_state, int transformation) {
    ball = Ball(global_state.balls(0));

    for (int i = 0; i < 3; i++) {
        team_blue[i] = Robot(global_state.robots_blue(i));
        team_yellow[i] = Robot(global_state.robots_yellow(i));
    }

    if (transformation == FieldTransformation::Flip180Degrees)
        spinField180Degrees();
}

void State::spinField180Degrees(){
    ball.spinField180Degrees();

    for (int i = 0; i < 3; i++) {
        team_blue[i].spinField180Degrees();
        team_yellow[i].spinField180Degrees();
    }
}