//
// Created by johnathan on 31/05/18.
//

#include <Domain/Ball.h>
#include <Domain/Robot.h>
#include <Domain/State.h>
#include <Domain/WheelsCommand.h>
#include <Domain/Command.h>
#include <Domain/Path.h>
#include <Constants.h>
#include <Domain/Debug.h>

namespace vss {

    namespace DomainRandomizer {

        vss::Point createRandomPoint() {
            srand(static_cast<unsigned int>(time(NULL)));

            vss::Point point;

            point.x = rand()%vss::MAX_COORDINATE_X;
            point.y = rand()%vss::MAX_COORDINATE_Y;

            return point;
        }

        vss::Pose createRandomPose() {
            srand(static_cast<unsigned int>(time(NULL)));

            vss::Pose pose;

            pose.x = rand()%vss::MAX_COORDINATE_X;
            pose.y = rand()%vss::MAX_COORDINATE_Y;
            pose.angle = rand()%vss::MAX_ANGLE_VALUE;

            return pose;
        }

        vss::Ball createRandomBall() {
            srand(static_cast<unsigned int>(time(NULL)));

            vss::Ball ball;

            ball.x = rand()%vss::MAX_COORDINATE_X;
            ball.y = rand()%vss::MAX_COORDINATE_Y;
            ball.speedX = rand()%2;
            ball.speedY = rand()%2;

            return ball;
        }

        vss::Robot createRandomRobot() {
            srand(static_cast<unsigned int>(time(NULL)));

            vss::Robot robot;

            robot.x = rand()%vss::MAX_COORDINATE_X;
            robot.y = rand()%vss::MAX_COORDINATE_Y;
            robot.angle = rand()%vss::MAX_ANGLE_VALUE;
            robot.speedX = rand()%2;
            robot.speedY = rand()%2;
            robot.speedAngle = rand()%2;

            return robot;
        }

        vss::Path createRandomPath() {
            srand(static_cast<unsigned int>(time(NULL)));
            vss::Path path;

            unsigned int size = rand()%10;

            for(unsigned int i = 0 ; i < size ; i++){
                path.points.push_back(createRandomPoint());
            }

            return path;
        }

        vss::State createRandomState(){
            srand(static_cast<unsigned int>(time(NULL)));
            vss::State state;

            unsigned int sizeTeamYellow = rand()%10;
            unsigned int sizeTeamBlue = rand()%10;
            state.ball = createRandomBall();

            for(unsigned int i = 0 ; i < sizeTeamYellow ; i++){
                state.teamYellow.push_back(createRandomRobot());
            }

            for(unsigned int i = 0 ; i < sizeTeamBlue ; i++){
                state.teamBlue.push_back(createRandomRobot());
            }

            return state;
        }

        vss::WheelsCommand createRandomWheelsCommand() {
            srand(static_cast<unsigned int>(time(NULL)));
            vss::WheelsCommand wheelsCommand;

            wheelsCommand.id = rand();
            wheelsCommand.leftVel = rand()%10;
            wheelsCommand.rightVel = rand()%10;

            return wheelsCommand;
        }

        vss::Command createRandomCommand() {
            srand(static_cast<unsigned int>(time(NULL)));
            vss::Command command;

            unsigned int size = rand()%10;
            command.id = rand();

            for(unsigned int i = 0 ; i < size ; i++){
                command.commands.push_back(createRandomWheelsCommand());
            }

            return command;
        }

        vss::Debug createRandomDebug() {
            srand(static_cast<unsigned int>(time(NULL)));
            vss::Debug debug;

            unsigned int robotsAmount = rand()%10;

            for(unsigned int i = 0 ; i < robotsAmount ; i++){
                debug.stepPoints.push_back(createRandomPoint());
                debug.finalPoses.push_back(createRandomPose());
                debug.paths.push_back(createRandomPath());
            }

            return debug;
        }

    }

}