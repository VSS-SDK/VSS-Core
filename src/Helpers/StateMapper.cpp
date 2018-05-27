//
// Created by johnathan on 27/05/18.
//

#include "Helpers/StateMapper.h"

namespace vss {
    namespace StateMapper {
        State globalStateToState(vss_state::Global_State _globalState){
            State state;

            state.ball = ballStateToBall(_globalState.balls(0));

            for (int i = 0; i < 3; i++) {
                state.teamBlue[i] = robotStateToRobot(_globalState.robots_blue(i));
                state.teamYellow[i] = robotStateToRobot(_globalState.robots_yellow(i));
            }

            return state;
        }

        Robot robotStateToRobot(vss_state::Robot_State robot_state) {
            Robot robot;

            robot.x = robot_state.pose().x();
            robot.y = robot_state.pose().y();
            robot.angle = robot_state.pose().yaw();

            robot.speedX = robot_state.v_pose().x();
            robot.speedY = robot_state.v_pose().y();
            robot.speedAngle = robot_state.v_pose().yaw();

            return robot;
        }

        Ball ballStateToBall(vss_state::Ball_State ball_state) {
            Ball ball;

            ball.x = ball_state.pose().x();
            ball.y = ball_state.pose().y();

            ball.speedX = ball_state.v_pose().x();
            ball.speedY = ball_state.v_pose().y();

            return ball;
        }
    }
}