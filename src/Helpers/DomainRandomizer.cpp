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
#include <Domain/Control.h>

namespace vss {

    namespace DomainRandomizer {

        vss::Point createRandomPoint() {
            srand(static_cast<unsigned int>(time(NULL)));

            vss::Point point;

            point.x = rand() % vss::MAX_COORDINATE_X;
            point.y = rand() % vss::MAX_COORDINATE_Y;

            return point;
        }

        vss::Pose createRandomPose() {
            srand(static_cast<unsigned int>(time(NULL)));

            vss::Pose pose;

            pose.x = rand() % vss::MAX_COORDINATE_X;
            pose.y = rand() % vss::MAX_COORDINATE_Y;
            pose.angle = rand() % vss::MAX_ANGLE_VALUE;

            return pose;
        }

        vss::Ball createRandomBall() {
            srand(static_cast<unsigned int>(time(NULL)));

            vss::Ball ball;

            ball.x = rand() % vss::MAX_COORDINATE_X;
            ball.y = rand() % vss::MAX_COORDINATE_Y;
            ball.speedX = (rand() % MAX_RANDOM_VELOCITY) * (rand()%2 == 0 ? -1 : 1);
            ball.speedY = (rand() % MAX_RANDOM_VELOCITY) * (rand()%2 == 0 ? -1 : 1);

            return ball;
        }

        vss::Robot createRandomRobot() {
            srand(static_cast<unsigned int>(time(NULL)));

            vss::Robot robot;

            robot.x = rand() % vss::MAX_COORDINATE_X;
            robot.y = rand() % vss::MAX_COORDINATE_Y;
            robot.angle = rand() % vss::MAX_ANGLE_VALUE;
            robot.speedX = (rand() % MAX_RANDOM_VELOCITY) * (rand()%2 == 0 ? -1 : 1);
            robot.speedY = (rand() % MAX_RANDOM_VELOCITY) * (rand()%2 == 0 ? -1 : 1);
            robot.speedAngle = (rand() % MAX_RANDOM_VELOCITY) * (rand()%2 == 0 ? -1 : 1);

            return robot;
        }

        vss::Path createRandomPath() {
            srand(static_cast<unsigned int>(time(NULL)));
            vss::Path path;

            auto size = static_cast<unsigned int>(rand() % MAX_RANDOM_PATH_SIZE);

            for(unsigned int i = 0 ; i < size ; i++){
                path.points.push_back(createRandomPoint());
            }

            return path;
        }

        vss::State createRandomState(){
            srand(static_cast<unsigned int>(time(NULL)));
            vss::State state;

            auto sizeTeamYellow = static_cast<unsigned int>(rand() % MAX_RANDOM_TEAM_SIZE);
            auto sizeTeamBlue = static_cast<unsigned int>(rand() % MAX_RANDOM_TEAM_SIZE);
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

            wheelsCommand.leftVel = (rand() % MAX_RANDOM_WHEEL_COMMAND) * (rand()%2 == 0 ? -1 : 1);
            wheelsCommand.rightVel = (rand() % MAX_RANDOM_WHEEL_COMMAND) * (rand()%2 == 0 ? -1 : 1);

            return wheelsCommand;
        }

        vss::Command createRandomCommand() {
            srand(static_cast<unsigned int>(time(NULL)));
            vss::Command command;

            auto size = static_cast<unsigned int>(rand() % MAX_RANDOM_TEAM_SIZE);

            for(unsigned int i = 0 ; i < size ; i++){
                command.commands.push_back(createRandomWheelsCommand());
            }

            return command;
        }

        vss::Debug createRandomDebug() {
            srand(static_cast<unsigned int>(time(NULL)));
            vss::Debug debug;

            auto robotsAmount = static_cast<unsigned int>(rand() % MAX_RANDOM_TEAM_SIZE);

            for(unsigned int i = 0 ; i < robotsAmount ; i++){
                debug.stepPoints.push_back(createRandomPoint());
                debug.finalPoses.push_back(createRandomPose());
                debug.paths.push_back(createRandomPath());
            }

            return debug;
        }

        vss::Control createRandomControl() {
            vss::Control control;

            control.paused = (rand()%2 == 0);
            control.ball = createRandomBall();

            auto robotsAmount = static_cast<unsigned int>(rand() % MAX_RANDOM_TEAM_SIZE);

            for(unsigned int i = 0 ; i < robotsAmount ; i++){
                control.teamYellow.push_back(createRandomRobot());
                control.teamBlue.push_back(createRandomRobot());
            }

            return control;
        }

    }

}