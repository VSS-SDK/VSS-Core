//
// Created by johnathan on 31/05/18.
//

#ifndef VSS_CORE_CONSTANTS_H
#define VSS_CORE_CONSTANTS_H

#include "string"

namespace vss {

    // Space Constraints
    const int MIN_COORDINATE_X = 0;
    const int MAX_COORDINATE_X = 170;
    const int MIN_COORDINATE_Y = 0;
    const int MAX_COORDINATE_Y = 130;
    const int MIN_ANGLE_VALUE = 0;
    const int MAX_ANGLE_VALUE = 360;

    // Randomization
    const int MAX_RANDOM_VELOCITY = 5;
    const int MAX_RANDOM_PATH_SIZE = 10;
    const int MAX_RANDOM_TEAM_SIZE = 11;
    const int MAX_RANDOM_WHEEL_COMMAND = 10;

    // Communication
    const int DEFAULT_STATE_PORT = 5555;
    const int DEFAULT_COMMAND_YELLOW_PORT = 5556;
    const int DEFAULT_COMMAND_BLUE_PORT = 5557;
    const int DEFAULT_DEBUG_YELLOW_PORT = 5558;
    const int DEFAULT_DEBUG_BLUE_PORT = 5550;
    const int DEFAULT_CONTROL_PORT = 5560;
    const std::string DEFAULT_STATE_SEND_ADDRESS = "tcp://*";
    const std::string DEFAULT_STATE_RECEIVE_ADDRESS = "tcp://localhost";
    const std::string DEFAULT_COMMAND_SEND_ADDRESS = "tcp://localhost";
    const std::string DEFAULT_COMMAND_RECEIVE_ADDRESS = "tcp://*";
    const std::string DEFAULT_DEBUG_SEND_ADDRESS = "tcp://localhost";
    const std::string DEFAULT_DEBUG_RECEIVE_ADDRESS = "tcp://*";
    const std::string DEFAULT_CONTROL_SEND_ADDRESS = "tcp://*";
    const std::string DEFAULT_CONTROL_RECEIVE_ADDRESS = "tcp://localhost";

}

#endif //VSS_CORE_CONSTANTS_H
