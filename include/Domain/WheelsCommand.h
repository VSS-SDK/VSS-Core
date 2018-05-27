//
// Created by johnathan on 27/05/18.
//

#ifndef VSS_CORE_WHEELSCOMMAND_H
#define VSS_CORE_WHEELSCOMMAND_H

namespace vss {

    class WheelsCommand {
    public:
        WheelsCommand();

        int id;
        float leftVel;
        float rightVel;
    };

}

#endif //VSS_CORE_WHEELSCOMMAND_H