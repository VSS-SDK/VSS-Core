#include "Helpers/CoordinateTransformer.h"

namespace vss{
    namespace CoordinateTransformer{
        State spinField180Degrees(State state){

            state.ball = spin180Degrees(state.ball);

            for (int i = 0; i < 3; i++) {
                state.teamBlue[i] = spin180Degrees(state.teamBlue[i]);
                state.teamYellow[i] = spin180Degrees(state.teamYellow[i]);
            }

            return state;
        }

        Robot spin180Degrees(Robot robot){
            // 170 is the size in x of the field
            robot.x = 170 - robot.x;
            // 130 is the size in y of the field
            robot.y = 130 - robot.y;

            if (robot.angle + 180 > 360){
                robot.angle = robot.angle - 180;
            } else {
                robot.angle = robot.angle + 180;
            }

            return robot;
        }

        Ball spin180Degrees(Ball ball){
            // 170 is the size in x of the field
            ball.x = 170 - ball.x;
            // 130 is the size in y of the field
            ball.y = 130 - ball.y;

            return ball;
        }
    }
}