#include "StateTransformation.h"

Robot StateTransformation::robotStateToRobot(vss_state::Robot_State robot_state) {
    Robot robot;

    robot.x = robot_state.pose().x();
    robot.y = robot_state.pose().y();
    robot.angle = robot_state.pose().yaw();
    
    robot.speedX = robot_state.v_pose().x();
    robot.speedY = robot_state.v_pose().y();
    robot.speedAngle = robot_state.v_pose().yaw();

    return robot;
}

Ball StateTransformation::ballStateToBall(vss_state::Ball_State ball_state) {
    Ball ball;

    ball.x = ball_state.pose().x();
    ball.y = ball_state.pose().y();

    ball.speedX = ball_state.v_pose().x();
    ball.speedY = ball_state.v_pose().y();
    
    return ball;
}