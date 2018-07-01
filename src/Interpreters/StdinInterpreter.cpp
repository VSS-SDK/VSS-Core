//
// Created by johnathan on 01/07/18.
//

#include <iostream>
#include <Interpreters/StdinInterpreter.h>
#include <Domain/StdinConfiguration.h>
#include <Domain/Constants.h>

namespace vss {

    StdinInterpreter::StdinInterpreter() {
        looksForStateReceiverAddress = false;
        looksForStateSenderAddress = false;
        looksForYellowCommandReceiverAddress = false;
        looksForYellowCommandSenderAddress = false;
        looksForYellowDebugReceiverAddress = false;
        looksForYellowDebugSenderAddress = false;
        looksForBlueCommandReceiverAddress = false;
        looksForBlueCommandSenderAddress = false;
        looksForBlueDebugReceiverAddress = false;
        looksForBlueDebugSenderAddress = false;
        looksForControlReceiverAddress = false;
        looksForControlSenderAddress = false;

        looksForStateCommunicationPort = false;
        looksForYellowCommandCommunicationPort = false;
        looksForYellowDebugCommunicationPort = false;
        looksForBlueCommandCommunicationPort = false;
        looksForBlueDebugCommunicationPort = false;
        looksForControlCommunicationPort = false;

        looksForTeamType = false;
        looksForSideAttackType = false;
        looksForTimeExecutionType = false;
        looksForEnvironmentType = false;

        stdinConfiguration.validConfiguration = false;
    }

    StdinConfiguration StdinInterpreter::extractConfiguration(int argc, char** argv) {
        try
        {
            auto desc = buildOptions();

            boost::program_options::variables_map vm;
            store(parse_command_line(argc, argv, desc), vm);
            notify(vm);

            if (vm.count("help")){
                std::cout << desc << '\n';
                return stdinConfiguration;
            }

            buildConfiguration(vm);

            return stdinConfiguration;
        }
        catch (const boost::program_options::error &ex)
        {
            std::cerr << ex.what() << '\n';
        }


        return stdinConfiguration;
    }

    boost::program_options::options_description StdinInterpreter::buildOptions() {
        boost::program_options::options_description desc{"Options"};

        desc.add_options()("help,h", "");

        // ADDRESS
        if(looksForStateReceiverAddress)
            desc.add_options()("state_send_address", boost::program_options::value<std::string>()->default_value(DEFAULT_STATE_SEND_ADDRESS), "");

        if(looksForStateReceiverAddress)
            desc.add_options()("state_receive_address", boost::program_options::value<std::string>()->default_value(DEFAULT_STATE_RECEIVE_ADDRESS), "");

        if(looksForYellowCommandSenderAddress)
            desc.add_options()("yellow_command_send_address", boost::program_options::value<std::string>()->default_value(DEFAULT_COMMAND_SEND_ADDRESS), "");

        if(looksForYellowCommandReceiverAddress)
            desc.add_options()("yellow_command_receive_address", boost::program_options::value<std::string>()->default_value(DEFAULT_COMMAND_RECEIVE_ADDRESS), "");

        if(looksForYellowDebugSenderAddress)
            desc.add_options()("yellow_debug_send_address", boost::program_options::value<std::string>()->default_value(DEFAULT_DEBUG_SEND_ADDRESS), "");

        if(looksForYellowDebugReceiverAddress)
            desc.add_options()("yellow_debug_receive_address", boost::program_options::value<std::string>()->default_value(DEFAULT_DEBUG_RECEIVE_ADDRESS), "");

        if(looksForBlueCommandSenderAddress)
            desc.add_options()("blue_command_send_address", boost::program_options::value<std::string>()->default_value(DEFAULT_COMMAND_SEND_ADDRESS), "");

        if(looksForBlueCommandReceiverAddress)
            desc.add_options()("blue_command_receive_address", boost::program_options::value<std::string>()->default_value(DEFAULT_COMMAND_RECEIVE_ADDRESS), "");

        if(looksForBlueDebugSenderAddress)
            desc.add_options()("blue_debug_send_address", boost::program_options::value<std::string>()->default_value(DEFAULT_DEBUG_SEND_ADDRESS), "");

        if(looksForBlueDebugReceiverAddress)
            desc.add_options()("blue_debug_receive_address", boost::program_options::value<std::string>()->default_value(DEFAULT_DEBUG_RECEIVE_ADDRESS), "");

        if(looksForControlReceiverAddress)
            desc.add_options()("control_send_address", boost::program_options::value<std::string>()->default_value(DEFAULT_CONTROL_SEND_ADDRESS), "");

        if(looksForControlReceiverAddress)
            desc.add_options()("control_receive_address", boost::program_options::value<std::string>()->default_value(DEFAULT_CONTROL_RECEIVE_ADDRESS), "");


        // PORTS
        if(looksForStateCommunicationPort)
            desc.add_options()("state_port", boost::program_options::value<int>()->default_value(DEFAULT_STATE_PORT), "");

        if(looksForYellowCommandCommunicationPort)
            desc.add_options()("yellow_command_port", boost::program_options::value<int>()->default_value(DEFAULT_COMMAND_YELLOW_PORT), "");

        if(looksForBlueCommandCommunicationPort)
            desc.add_options()("blue_command_port", boost::program_options::value<int>()->default_value(DEFAULT_COMMAND_BLUE_PORT), "");

        if(looksForYellowDebugCommunicationPort)
            desc.add_options()("yellow_debug_port", boost::program_options::value<int>()->default_value(DEFAULT_DEBUG_YELLOW_PORT), "");

        if(looksForBlueDebugCommunicationPort)
            desc.add_options()("blue_debug_port", boost::program_options::value<int>()->default_value(DEFAULT_DEBUG_BLUE_PORT), "");

        if(looksForStateCommunicationPort)
            desc.add_options()("control_port", boost::program_options::value<int>()->default_value(DEFAULT_CONTROL_PORT), "");


        // Types
        if(looksForTeamType)
            desc.add_options()("team_type", boost::program_options::value<std::string>()->default_value("Yellow"), "");

        if(looksForSideAttackType)
            desc.add_options()("side_attack_type", boost::program_options::value<std::string>()->default_value("Left"), "");

        if(looksForTimeExecutionType)
            desc.add_options()("time_execution_type", boost::program_options::value<std::string>()->default_value("Normal"), "");

        if(looksForEnvironmentType)
            desc.add_options()("environment_type", boost::program_options::value<std::string>()->default_value("Simulation"), "");


        return desc;
    }

    void StdinInterpreter::buildConfiguration(boost::program_options::variables_map vm) {
        // ADDRESS
        if(vm.count("state_send_address"))
            stdinConfiguration.stateSenderAddress.setIp(vm["state_send_address"].as<std::string>());

        if(vm.count("state_receive_address"))
            stdinConfiguration.stateReceiverAddress.setIp(vm["state_receive_address"].as<std::string>());

        if(vm.count("yellow_command_send_address"))
            stdinConfiguration.commandYellowSenderAddress.setIp(vm["yellow_command_send_address"].as<std::string>());

        if(vm.count("yellow_command_receive_address"))
            stdinConfiguration.commandYellowReceiverAddress.setIp(vm["yellow_command_receive_address"].as<std::string>());

        if(vm.count("yellow_debug_send_address"))
            stdinConfiguration.debugYellowSenderAddress.setIp(vm["yellow_debug_send_address"].as<std::string>());

        if(vm.count("yellow_debug_receive_address"))
            stdinConfiguration.debugYellowReceiverAddress.setIp(vm["yellow_debug_receive_address"].as<std::string>());

        if(vm.count("blue_command_send_address"))
            stdinConfiguration.commandBlueSenderAddress.setIp(vm["blue_command_send_address"].as<std::string>());

        if(vm.count("blue_command_receive_address"))
            stdinConfiguration.commandBlueReceiverAddress.setIp(vm["blue_command_receive_address"].as<std::string>());

        if(vm.count("blue_debug_send_address"))
            stdinConfiguration.debugBlueSenderAddress.setIp(vm["blue_debug_send_address"].as<std::string>());

        if(vm.count("blue_debug_receive_address"))
            stdinConfiguration.debugBlueReceiverAddress.setIp(vm["blue_debug_receive_address"].as<std::string>());


        // PORTS
        if(vm.count("state_port")){
            stdinConfiguration.stateSenderAddress.setPort(vm["state_port"].as<int>());
            stdinConfiguration.stateReceiverAddress.setPort(vm["state_port"].as<int>());
        }

        if(vm.count("yellow_command_port")){
            stdinConfiguration.commandYellowSenderAddress.setPort(vm["state_port"].as<int>());
            stdinConfiguration.commandYellowReceiverAddress.setPort(vm["state_port"].as<int>());
        }

        if(vm.count("blue_command_port")){
            stdinConfiguration.commandBlueSenderAddress.setPort(vm["blue_command_port"].as<int>());
            stdinConfiguration.commandBlueReceiverAddress.setPort(vm["blue_command_port"].as<int>());
        }

        if(vm.count("yellow_debug_port")){
            stdinConfiguration.debugYellowSenderAddress.setPort(vm["yellow_debug_port"].as<int>());
            stdinConfiguration.debugYellowReceiverAddress.setPort(vm["yellow_debug_port"].as<int>());
        }

        if(vm.count("blue_debug_port")){
            stdinConfiguration.debugBlueSenderAddress.setPort(vm["blue_debug_port"].as<int>());
            stdinConfiguration.debugBlueReceiverAddress.setPort(vm["blue_debug_port"].as<int>());
        }

        if(vm.count("control_port")){
            stdinConfiguration.controlSenderAddress.setPort(vm["control_port"].as<int>());
            stdinConfiguration.controlReceiverAddress.setPort(vm["control_port"].as<int>());
        }


        // TYPES
        if(vm.count("team_type"))
            stdinConfiguration.teamType = toTeamType(vm["team_type"].as<std::string>());

        if(vm.count("side_attack_type"))
            stdinConfiguration.sideAttackType = toSideAttackType(vm["side_attack_type"].as<std::string>());

        if(vm.count("time_execution_type"))
            stdinConfiguration.timeExecutionType = toTimeExecutionType(vm["time_execution_type"].as<std::string>());

        if(vm.count("environment_type"))
            stdinConfiguration.environmentType = toEnvironmentType(vm["environment_type"].as<std::string>());


        stdinConfiguration.validConfiguration = true;
    }

};