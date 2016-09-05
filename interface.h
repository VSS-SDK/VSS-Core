/*
 * This file is part of the VSS-SDK project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include <sstream>
#include <iostream>
#include <string>
#include "unistd.h"

#include "zmq.hpp"
#include <google/protobuf/text_format.h>
#include "protos/state.pb.h"
#include "protos/command.pb.h"
#include "protos/debug.pb.h"

class Interface{
private:
	zmq::context_t *context;
    zmq::socket_t *socket;

	zmq::context_t *context_command_yellow;
    zmq::socket_t *socket_command_yellow;

	zmq::context_t *context_command_blue;
    zmq::socket_t *socket_command_blue;

	zmq::context_t *context_debug;
	zmq::socket_t *socket_debug;
    
	vss_state::Global_State *global_state;
	vss_command::Global_Commands *global_commands;
	vss_debug::Global_Debug *global_debug;
	
	// Simulator and VSS -> Strategies
	const char *addr_server_multicast = "tcp://*:5555";
	const char *addr_client_multicast = "tcp://localhost:5555";

	// Strategy Team 1 -> Simulator
	const char *addr_server_simulator_team1 = "tcp://*:5556";
	const char *addr_client_simulator_team1 = "tcp://localhost:5556";

	// Strategy Team 2 -> Simulator
	const char *addr_server_simulator_team2 = "tcp://*:5557";
	const char *addr_client_simulator_team2 = "tcp://localhost:5557";

	// Strategy Team 1 -> Viewer
	const char *addr_server_debug_team1 = "tcp://*:5558";
	const char *addr_client_debug_team1 = "tcp://localhost:5558";

	// Strategy Team 2 -> Viewer
	const char *addr_server_debug_team2 = "tcp://*:5559";
	const char *addr_client_debug_team2 = "tcp://localhost:5559";
public:
	Interface();

	void createSocketSendState(vss_state::Global_State*);
	void sendState();
	void createSocketReceiveState(vss_state::Global_State*);
	void receiveState();

	void createSendCommandsTeam1(vss_command::Global_Commands*);
	void sendCommandTeam1();
	void createReceiveCommandsTeam1(vss_command::Global_Commands*);
	void receiveCommandTeam1();

	void createSendCommandsTeam2(vss_command::Global_Commands*);
	void sendCommandTeam2();
	void createReceiveCommandsTeam2(vss_command::Global_Commands*);	
	void receiveCommandTeam2();

	void createSendDebugTeam1(vss_debug::Global_Debug*);
	void sendDebugTeam1();
	void createReceiveDebugTeam1(vss_debug::Global_Debug*);
	void receiveDebugTeam1();

	void createSendDebugTeam2(vss_debug::Global_Debug*);
	void sendDebugTeam2();
	void createReceiveDebugTeam2(vss_debug::Global_Debug*);	
	void receiveDebugTeam2();

	void printState();
	void printCommand();
	void printDebug();
};

#endif // _INTERFACE_H_