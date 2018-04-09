#include "robot.h"

Robot::Robot() {}

Robot::Robot(vss_state::Robot_State robot_state) {
    robotStateToRobot(robot_state);
}

void Robot::robotStateToRobot(vss_state::Robot_State robot_state) {
    x = robot_state.pose().x();
    y = robot_state.pose().y();
    angle = robot_state.pose().yaw();
    
    speed_x = robot_state.v_pose().x();
    speed_y = robot_state.v_pose().y();
    speed_angle = robot_state.v_pose().yaw();
}