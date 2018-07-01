//
// Created by johnathan on 01/07/18.
//

#include <boost/program_options.hpp>
#include <iostream>
#include <Interpreters/StdinInterpreter.h>
#include <Domain/StdinConfiguration.h>
#include <Domain/Constants.h>

namespace vss {

    StdinInterpreter::StdinInterpreter() {
        looksForStateReceiverAddress = true;
        looksForStateSenderAddress = true;
        looksForYellowCommandReceiverAddress = true;
        looksForYellowCommandSenderAddress = true;
        looksForYellowDebugReceiverAddress = true;
        looksForYellowDebugSenderAddress = true;
        looksForBlueCommandReceiverAddress = true;
        looksForBlueCommandSenderAddress = true;
        looksForBlueDebugReceiverAddress = true;
        looksForBlueDebugSenderAddress = true;
        looksForControlReceiverAddress = true;
        looksForControlSenderAddress = true;

        looksForStateCommunicationPort = true;
        looksForYellowCommandCommunicationPort = true;
        looksForYellowDebugCommunicationPort = true;
        looksForBlueCommandCommunicationPort = true;
        looksForBlueDebugCommunicationPort = true;
        looksForControlCommunicationPort = true;

        looksForTeamType = true;
        looksForSideAttackType = true;
        looksForTimeExecutionType = true;
    }

    StdinConfiguration StdinInterpreter::extractConfiguration(int argc, char** argv) {
        StdinConfiguration stdinConfiguration;

        try
        {
            auto desc = buildOptions();

            boost::program_options::variables_map vm;
            store(parse_command_line(argc, argv, desc), vm);
            notify(vm);

            std::cout << desc << '\n';

            /*if (vm.count("help"))
                std::cout << desc << '\n';
            else if (vm.count("age"))
                std::cout << "Age: " << vm["age"].as<int>() << '\n';
            else if (vm.count("pi"))
                std::cout << "Pi: " << vm["pi"].as<float>() << '\n';*/
        }
        catch (const boost::program_options::error &ex)
        {
            std::cerr << ex.what() << '\n';
        }


        return stdinConfiguration;
    }

    boost::program_options::options_description StdinInterpreter::buildOptions() {
        boost::program_options::options_description desc{"Options"};

        desc.add_options()("help,h", "Help screen");

        // ADDRESS
        if(looksForStateReceiverAddress)
            desc.add_options()("state_send_address,ssa", boost::program_options::value<std::string>()->default_value(DEFAULT_STATE_SEND_ADDRESS), "State Sender Address");

        if(looksForStateReceiverAddress)
            desc.add_options()("state_receive_address,sra", boost::program_options::value<std::string>()->default_value(DEFAULT_STATE_RECEIVE_ADDRESS), "State Receiver Address");

        if(looksForYellowCommandSenderAddress)
            desc.add_options()("yellow_command_send_address,ycsa", boost::program_options::value<std::string>()->default_value(DEFAULT_COMMAND_SEND_ADDRESS), "Yellow Command Sender Address");

        if(looksForYellowCommandReceiverAddress)
            desc.add_options()("yellow_command_receive_address,ycra", boost::program_options::value<std::string>()->default_value(DEFAULT_COMMAND_RECEIVE_ADDRESS), "Yellow Command Receiver Address");

        if(looksForYellowDebugSenderAddress)
            desc.add_options()("yellow_debug_send_address,ydsa", boost::program_options::value<std::string>()->default_value(DEFAULT_DEBUG_SEND_ADDRESS), "Yellow Debug Sender Address");

        if(looksForYellowDebugReceiverAddress)
            desc.add_options()("yellow_debug_receive_address,ydra", boost::program_options::value<std::string>()->default_value(DEFAULT_DEBUG_RECEIVE_ADDRESS), "Yellow Debug Receiver Address");

        if(looksForBlueCommandSenderAddress)
            desc.add_options()("blue_command_send_address,bcsa", boost::program_options::value<std::string>()->default_value(DEFAULT_COMMAND_SEND_ADDRESS), "Blue Command Sender Address");

        if(looksForBlueCommandReceiverAddress)
            desc.add_options()("blue_command_receive_address,bcra", boost::program_options::value<std::string>()->default_value(DEFAULT_COMMAND_RECEIVE_ADDRESS), "Blue Command Receiver Address");

        if(looksForBlueDebugSenderAddress)
            desc.add_options()("blue_debug_send_address,bdsa", boost::program_options::value<std::string>()->default_value(DEFAULT_DEBUG_SEND_ADDRESS), "Blue Debug Sender Address");

        if(looksForBlueDebugReceiverAddress)
            desc.add_options()("blue_debug_receive_address,bdra", boost::program_options::value<std::string>()->default_value(DEFAULT_DEBUG_RECEIVE_ADDRESS), "Blue Debug Receiver Address");

        if(looksForControlReceiverAddress)
            desc.add_options()("control_send_address,csa", boost::program_options::value<std::string>()->default_value(DEFAULT_CONTROL_SEND_ADDRESS), "Control Sender Address");

        if(looksForControlReceiverAddress)
            desc.add_options()("control_receive_address,cra", boost::program_options::value<std::string>()->default_value(DEFAULT_CONTROL_RECEIVE_ADDRESS), "Control Receiver Address");


        // PORTS
        if(looksForStateCommunicationPort)
            desc.add_options()("state_port,sp", boost::program_options::value<int>()->default_value(DEFAULT_STATE_PORT), "State Communication Port");

        if(looksForYellowCommandCommunicationPort)
            desc.add_options()("yellow_command_port,ymp", boost::program_options::value<int>()->default_value(DEFAULT_COMMAND_YELLOW_PORT), "Yellow Command Communication Port");

        if(looksForBlueCommandCommunicationPort)
            desc.add_options()("blue_command_port,bmp", boost::program_options::value<int>()->default_value(DEFAULT_COMMAND_BLUE_PORT), "Blue Command Communication Port");

        if(looksForYellowDebugCommunicationPort)
            desc.add_options()("yellow_debug_port,ydp", boost::program_options::value<int>()->default_value(DEFAULT_DEBUG_YELLOW_PORT), "Yellow Debug Communication Port");

        if(looksForBlueDebugCommunicationPort)
            desc.add_options()("blue_debug_port,bdp", boost::program_options::value<int>()->default_value(DEFAULT_DEBUG_BLUE_PORT), "Yellow Debug Communication Port");

        if(looksForStateCommunicationPort)
            desc.add_options()("control_port,cp", boost::program_options::value<int>()->default_value(DEFAULT_CONTROL_PORT), "Control Communication Port");


        // Types
        if(looksForTeamType)
            desc.add_options()("team_type,tt", boost::program_options::value<std::string>()->default_value("Yellow"), "Team Type");

        if(looksForSideAttackType)
            desc.add_options()("side_attack_type,sat", boost::program_options::value<std::string>()->default_value("Left"), "Side Attack Type");

        if(looksForTimeExecutionType)
            desc.add_options()("time_exection_type,tet", boost::program_options::value<std::string>()->default_value("Normal"), "Time Execution Type");

        return desc;
    }

};