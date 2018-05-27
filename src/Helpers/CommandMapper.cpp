//
// Created by johnathan on 27/05/18.
//

#include <iostream>
#include "Helpers/CommandMapper.h"

namespace vss {

    vss_command::Global_Commands CommandMapper::commandToGlobalCommands(Command command) {
        vss_command::Global_Commands commands;

        commands.set_id(static_cast<google::protobuf::uint32>(command.id));

        for (unsigned int i = 0; i < command.commands.size() ; i++) {
            auto ref = commands.add_robot_commands();
            ref->set_id(static_cast<google::protobuf::uint32>(command.commands[i].id));
            ref->set_left_vel(command.commands[i].leftVel);
            ref->set_right_vel(command.commands[i].rightVel);
        }

        return commands;
    }
}

