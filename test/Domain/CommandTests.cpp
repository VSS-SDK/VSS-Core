//
// Created by johnathan on 30/05/18.
//

#include <googletest/googletest/include/gtest/gtest.h>
#include "Domain/Command.h"

TEST(Command_Constructor, WhenDefaultBuilded_ShouldBeZero){
    vss::Command command;

    EXPECT_EQ(command.id, 0);
    EXPECT_EQ(command.commands.size(), (unsigned int)0);
}

TEST(Command_Constructor, WhenParameterBuilded_ShouldHaveSameValues){
    srand(static_cast<unsigned int>(time(NULL)));

    int id = rand();
    int size = rand()%10;
    std::vector<vss::WheelsCommand> wheelsCommands;

    for(int i = 0 ; i < size ; i++){
        vss::WheelsCommand wheelsCommand;

        wheelsCommand.id = rand();
        wheelsCommand.leftVel = rand();
        wheelsCommand.rightVel = rand();

        wheelsCommands.push_back(wheelsCommand);
    }

    vss::Command command(id, wheelsCommands);

    EXPECT_EQ(command.id, id);
    EXPECT_EQ(command.commands.size(), (unsigned int)size);

    for(unsigned int i = 0 ; i < command.commands.size() ; i++){
        EXPECT_EQ(command.commands[i].id, wheelsCommands[i].id);
        EXPECT_EQ(command.commands[i].leftVel, wheelsCommands[i].leftVel);
        EXPECT_EQ(command.commands[i].rightVel, wheelsCommands[i].rightVel);
    }
}