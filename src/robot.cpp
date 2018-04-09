#include "robot.h"

Robot::Robot() {}

Robot::Robot(vss_state::Robot_State robot_state) {
    robotStateToRobot(robot_state);
}

void Robot::robotStateToRobot(vss_state::Robot_State robot_state) {
    m_x = robot_state.pose().x();
    m_y = robot_state.pose().y();
    m_angle = robot_state.pose().yaw();
    
    m_speed_x = robot_state.v_pose().x();
    m_speed_y = robot_state.v_pose().y();
    m_speed_angle = robot_state.v_pose().yaw();
}