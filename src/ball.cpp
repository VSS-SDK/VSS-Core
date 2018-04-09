#include "ball.h"

Ball::Ball() {
}

Ball::Ball(vss_state::Ball_State ball_state) {
    ballStateToBall(ball_state);
}

void Ball::ballStateToBall(vss_state::Ball_State ball_state) {
    x = ball_state.pose().x();
    y = ball_state.pose().y();

    speed_x = ball_state.v_pose().x();
    speed_y = ball_state.v_pose().y();
}