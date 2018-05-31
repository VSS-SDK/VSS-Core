//
// Created by johnathan on 31/05/18.
//

#ifndef VSS_CORE_DOMAINRANDOMIZER_H
#define VSS_CORE_DOMAINRANDOMIZER_H

#include <Domain/Ball.h>
#include <Domain/Robot.h>
#include <Domain/State.h>
#include <Domain/WheelsCommand.h>
#include <Domain/Command.h>
#include <Domain/Path.h>

namespace vss {

    namespace DomainRandomizer {

        vss::Point createRandomPoint();
        vss::Pose createRandomPose();
        vss::Ball createRandomBall();
        vss::Robot createRandomRobot();
        vss::Path createRandomPath();
        vss::State createRandomState();
        vss::WheelsCommand createRandomWheelsCommand();
        vss::Command createRandomCommand();


    }

}

#endif //VSS_CORE_DOMAINRANDOMIZER_H
