//
// Created by johnathan on 27/05/18.
//

#ifndef VSS_CORE_STATEMAPPER_H
#define VSS_CORE_STATEMAPPER_H

#include <state.pb.h>
#include "Domain/State.h"
#include "Domain/Robot.h"
#include "Domain/Ball.h"

namespace vss {
    namespace StateMapper {
        State globalStateToState(vss_state::Global_State _globalState);
        Robot robotStateToRobot(vss_state::Robot_State robot_state);
        Ball ballStateToBall(vss_state::Ball_State ball_state);
    }
}

#endif //VSS_CORE_STATEMAPPER_H
