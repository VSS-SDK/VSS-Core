/*
 * This file is part of the VSS-SDK project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#include "interface.h"

Interface::Interface(){
}

void Interface::createSocketSendState(vss_state::Global_State *global_state, string addr_server_multicast){
	this->global_state = global_state;
	this->addr_server_multicast = addr_server_multicast;

	context = new zmq::context_t(1);
	socket = new zmq::socket_t(*context, ZMQ_PUB);

	std::cout << "Connecting Server Multicast Sender: " << addr_server_multicast << std::endl;
	socket->bind(addr_server_multicast);
}

void Interface::sendState(){
	std::string msg_str;
    global_state->SerializeToString(&msg_str);

    zmq::message_t request (msg_str.size());
    memcpy ((void *) request.data (), msg_str.c_str(), msg_str.size());
    //std::cout << "Sending State data ..." << std::endl;
    socket->send(request);
}

void Interface::createSocketReceiveState(vss_state::Global_State *global_state, string addr_client_multicast){
	this->global_state = global_state;
	this->addr_client_multicast = addr_client_multicast;
	
	context = new zmq::context_t(1);
	socket = new zmq::socket_t(*context, ZMQ_SUB);

	std::cout << "Connecting Client Multicast Receiver: " << addr_client_multicast << std::endl;
	socket->connect(addr_client_multicast);

	socket->setsockopt(ZMQ_SUBSCRIBE, "", 0);
}

void Interface::receiveState(){
	zmq::message_t request;
	socket->recv(&request, 0); //  Wait for next request from client
	//std::cout << "Received" << std::endl;
	std::string msg_str(static_cast<char*>(request.data()), request.size());
	global_state->ParseFromString(msg_str);
	//printState();
}

void Interface::createSendCommandsTeam1(vss_command::Global_Commands* global_commands, string addr_client_simulator_team1){
	this->global_commands = global_commands;
	this->addr_client_simulator_team1 = addr_client_simulator_team1;
	
	context_command_yellow = new zmq::context_t(1);
	socket_command_yellow = new zmq::socket_t(*context_command_yellow, ZMQ_PAIR);

	std::cout << "Connecting Client Sender Team 1: " << addr_client_simulator_team1 << "(yellow team)" << std::endl << std::endl;
	socket_command_yellow->connect(addr_client_simulator_team1);
}

void Interface::sendCommandTeam1(){
	std::string msg_str;
	global_commands->SerializeToString(&msg_str);

	zmq::message_t request (msg_str.size());
	memcpy ((void *) request.data (), msg_str.c_str(), msg_str.size());
	//std::cout << "Sending State data ..." << std::endl;
	socket_command_yellow->send(request);
	//printCommand();
}

void Interface::createSendCommandsTeam2(vss_command::Global_Commands* global_commands, string addr_client_simulator_team2){
	this->global_commands = global_commands;
	this->addr_client_simulator_team2 = addr_client_simulator_team2;
	
	context_command_blue = new zmq::context_t(1);
	socket_command_blue = new zmq::socket_t(*context_command_blue, ZMQ_PAIR);

	std::cout << "Connecting Client Sender Team 2: " << addr_client_simulator_team2 << "(blue team)" << std::endl << std::endl;
	socket_command_blue->connect(addr_client_simulator_team2);
}

void Interface::sendCommandTeam2(){
	std::string msg_str;
	global_commands->SerializeToString(&msg_str);

	zmq::message_t request (msg_str.size());
	memcpy ((void *) request.data (), msg_str.c_str(), msg_str.size());
	//std::cout << "Sending State data ..." << std::endl;
	socket_command_blue->send(request);
	//printCommand();
}

void Interface::createReceiveCommandsTeam1(vss_command::Global_Commands* global_commands, string addr_server_simulator_team1){
	this->global_commands = global_commands;
	this->addr_server_simulator_team1 = addr_server_simulator_team1;

	context_command_yellow = new zmq::context_t(1);
	socket_command_yellow = new zmq::socket_t(*context_command_yellow, ZMQ_PAIR);

	std::cout << "Connecting Server Receiver Team 1: " << addr_server_simulator_team1 << std::endl;
	socket_command_yellow->bind(addr_server_simulator_team1);
}

void Interface::receiveCommandTeam1(){
	zmq::message_t request;
	socket_command_yellow->recv(&request);
	//std::cout << "Received" << std::endl;
	std::string msg_str(static_cast<char*>(request.data()), request.size());
	global_commands->ParseFromString(msg_str);
	//printCommand();
	//socket.close();
}

void Interface::createReceiveCommandsTeam2(vss_command::Global_Commands* global_commands, string addr_server_simulator_team2){
	this->global_commands = global_commands;
	this->addr_server_simulator_team2 = addr_server_simulator_team2;

	context_command_blue = new zmq::context_t(1);
	socket_command_blue = new zmq::socket_t(*context_command_blue, ZMQ_PAIR);

	std::cout << "Connecting Server Receiver Team 2: " << addr_server_simulator_team2 << std::endl;
	socket_command_blue->bind(addr_server_simulator_team2);
}

void Interface::receiveCommandTeam2(){
	zmq::message_t request;
	socket_command_blue->recv(&request);
	//std::cout << "Received" << std::endl;
	std::string msg_str(static_cast<char*>(request.data()), request.size());
	global_commands->ParseFromString(msg_str);
	//printCommand();
}

void Interface::createSendDebugTeam1(vss_debug::Global_Debug* global_debug, string addr_client_debug_team1){
	this->global_debug = global_debug;
	this->addr_client_debug_team1 = addr_client_debug_team1;
	
	context_debug = new zmq::context_t(1);
	socket_debug = new zmq::socket_t(*context_debug, ZMQ_PAIR);

	std::cout << "Connecting Server Sender Debug Team 1: " << addr_client_debug_team1 << "(yellow team)" << std::endl << std::endl;
	socket_debug->connect(addr_client_debug_team1);
}

void Interface::sendDebugTeam1(){
	std::string msg_str;
	global_debug->SerializeToString(&msg_str);

	zmq::message_t request (msg_str.size());
	memcpy ((void *) request.data (), msg_str.c_str(), msg_str.size());
	//std::cout << "Sending State data ..." << std::endl;
	socket_debug->send(request);
	//printCommand();
}

void Interface::createReceiveDebugTeam1(vss_debug::Global_Debug* global_debug, string addr_server_debug_team1){
	this->global_debug = global_debug;
	this->addr_server_debug_team1 = addr_server_debug_team1;

	context_debug = new zmq::context_t(1);
	socket_debug = new zmq::socket_t(*context_debug, ZMQ_PAIR);

	std::cout << "Connecting Client Receiver Debug Team 1: " << addr_server_debug_team1 << std::endl;
	socket_debug->bind(addr_server_debug_team1);
}

void Interface::receiveDebugTeam1(){
	zmq::message_t request;
	socket_debug->recv(&request);
	//std::cout << "Received" << std::endl;
	std::string msg_str(static_cast<char*>(request.data()), request.size());
	global_debug->ParseFromString(msg_str);
	//printCommand();
	//socket.close();
}

void Interface::createSendDebugTeam2(vss_debug::Global_Debug* global_debug, string addr_client_debug_team2){
	this->global_debug = global_debug;
	this->addr_client_debug_team2 = addr_cliet_debug_team2;
	
	context_debug = new zmq::context_t(1);
	socket_debug = new zmq::socket_t(*context_debug, ZMQ_PAIR);

	std::cout << "Connecting Server Sender Debug Team 2: " << addr_client_debug_team2 << " (blue team)" << std::endl << std::endl;
	socket_debug->connect(addr_client_debug_team2);
}

void Interface::sendDebugTeam2(){
	std::string msg_str;
	global_debug->SerializeToString(&msg_str);

	zmq::message_t request (msg_str.size());
	memcpy ((void *) request.data (), msg_str.c_str(), msg_str.size());
	//std::cout << "Sending State data ..." << std::endl;
	socket_debug->send(request);
	//printCommand();
}

void Interface::createReceiveDebugTeam2(vss_debug::Global_Debug* global_debug, string addr_server_debug_team2){
	this->global_debug = global_debug;
	this->addr_server_debug_team2 = addr_server_debug_team2;

	context_debug = new zmq::context_t(1);
	socket_debug = new zmq::socket_t(*context_debug, ZMQ_PAIR);

	std::cout << "Connecting Client Receiver Debug Team 2: " << addr_server_debug_team2 << std::endl;
	socket_debug->bind(addr_server_debug_team2);
}

void Interface::receiveDebugTeam2(){
	zmq::message_t request;
	socket_debug->recv(&request);
	//std::cout << "Received" << std::endl;
	std::string msg_str(static_cast<char*>(request.data()), request.size());
	global_debug->ParseFromString(msg_str);
	//printCommand();
	//socket.close();
}

void Interface::printState(){
	std::string text_str;
    google::protobuf::TextFormat::PrintToString(*global_state, &text_str);
    std::cout << text_str << std::endl;
}

void Interface::printCommand(){
	std::string text_str;
    google::protobuf::TextFormat::PrintToString(*global_commands, &text_str);
    std::cout << text_str << std::endl;
}

void Interface::printDebug(){
	std::string text_str;
    google::protobuf::TextFormat::PrintToString(*global_debug, &text_str);
    std::cout << text_str << std::endl;
}