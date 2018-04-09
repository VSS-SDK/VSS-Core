#include "ball.h"

Ball::Ball() {
}

Ball::Ball(vss_state::Ball_State ball_state) {
    ballStateToBall(ball_state);
}

void Ball::ballStateToBall(vss_state::Ball_State ball_state) {
    m_x = ball_state.pose().x();
    m_y = ball_state.pose().y();

    m_speed_x = ball_state.v_pose().x();
    m_speed_y = ball_state.v_pose().y();
}