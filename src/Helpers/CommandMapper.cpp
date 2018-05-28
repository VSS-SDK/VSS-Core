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
            setupWheelCommand(ref, command.commands[i]);
        }

        return commands;
    }

    void CommandMapper::setupWheelCommand(vss_command::Robot_Command *robotCommand, WheelsCommand wheelsCommand) {
        robotCommand->set_id(static_cast<google::protobuf::uint32>(wheelsCommand.id));
        robotCommand->set_left_vel(wheelsCommand.leftVel);
        robotCommand->set_right_vel(wheelsCommand.rightVel);
    }

    Command CommandMapper::globalCommandsToCommand(vss_command::Global_Commands globalCommands) {
        Command command;

        command.id = globalCommands.id();

        for (int i = 0 ; i < globalCommands.robot_commands_size() ; i++){
            WheelsCommand wheelsCommand;
            wheelsCommand.id = globalCommands.robot_commands(i).id();
            wheelsCommand.rightVel = globalCommands.robot_commands(i).right_vel();
            wheelsCommand.leftVel = globalCommands.robot_commands(i).left_vel();

            command.commands.push_back(wheelsCommand);
        }

        return command;
    }
}

