/*
 * This file is part of the VSS-SDK project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#include "InterfaceCore.h"

InterfaceCore::InterfaceCore(){
	cout << FieldTransformation::Flip180Degrees << endl;
}

//! Esse método deve ser chamado apenas uma vez
void InterfaceCore::createSocketReceiveState( vss_state::Global_State *global_state, string addr_client_multicast ){
	//! Global_State é recebido como ponteiro, assim facilitando o recebimento de novos estados
	this->global_state = global_state;
	this->addr_client_multicast = addr_client_multicast;

	context = new zmq::context_t( 1 );
	socket = new zmq::socket_t( *context, ZMQ_SUB );

	std::cout << "Connecting Client Multicast Receiver: " << addr_client_multicast << std::endl;
	socket->connect( addr_client_multicast.c_str());

	socket->setsockopt( ZMQ_SUBSCRIBE, "", 0 );
}

//! Esse método deve ser chamado em um loop infinito controlado.
//! O recebimento tratado aqui é não bloqueante
void InterfaceCore::receiveState(FieldTransformation::Transformation userTransformation){

	State state;

		state.ball = StateTransformation::ballStateToBall(global_state->balls(0));
		
		for (int i = 0; i < 3; i++) {
			state.teamBlue[i] = StateTransformation::robotStateToRobot(global_state->robots_blue(i));
			state.teamYellow[i] = StateTransformation::robotStateToRobot(global_state->robots_yellow(i));
		}

		if (userTransformation == FieldTransformation::Flip180Degrees)
			state = FieldTransformation::spinField180Degrees(state);
	
	//! Chamando esse método, o Global_State passado por ponteiro na construção do socket automaticamente é atualizado
	zmq::message_t request;
	socket->recv( &request, 0 ); //  Wait for next request from client
	//std::cout << "Received" << std::endl;
	std::string msg_str( static_cast<char*>(request.data()), request.size());
	global_state->ParseFromString( msg_str );
	//printState();
}