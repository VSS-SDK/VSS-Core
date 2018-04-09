#include "robot.h"

Robot::Robot(vss_state::Robot_State _robot_state) {
    robot_state = _robot_state;
    globalState2Robot();
}

void Robot::globalState2Robot() {
    m_x = robot_state.pose().x();
    m_y = robot_state.pose().y();
    m_angle = robot_state.pose().yaw();
    
    m_speed_x = robot_state.v_pose().x();
    m_speed_y = robot_state.v_pose().y();
    m_speed_angle = robot_state.v_pose().yaw();
}

float Robot::x(){
    return m_x;
}

float Robot::y(){
    return m_y;
}

float Robot::angle(){
    return m_angle;
}

float Robot::radian_angle(){
    return (2 * M_PI * m_angle) / 360;
}