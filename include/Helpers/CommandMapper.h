//
// Created by johnathan on 27/05/18.
//

#ifndef VSS_CORE_COMMANDMAPPER_H
#define VSS_CORE_COMMANDMAPPER_H

#include <command.pb.h>
#include <Domain/Command.h>

namespace vss {
    namespace CommandMapper {
        vss_command::Global_Commands commandToGlobalCommands(Command command);
        vss_command::Robot_Command wheelsCommandToRobotCommand(WheelsCommand wheelsCommand);
    }
}

#endif //VSS_CORE_COMMANDMAPPER_H
