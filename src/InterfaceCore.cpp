/*
 * This file is part of the VSS-SDK project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#include "InterfaceCore.h"

InterfaceCore::InterfaceCore(){
}

//! Esse método deve ser chamado apenas uma vez
void InterfaceCore::createSocketReceiveState( string addr_client_multicast ){
	this->addr_client_multicast = addr_client_multicast;

	context = new zmq::context_t( 1 );
	socket = new zmq::socket_t( *context, ZMQ_SUB );

	std::cout << "Connecting Client Multicast Receiver: " << addr_client_multicast << std::endl;
	socket->connect( addr_client_multicast.c_str());

	socket->setsockopt( ZMQ_SUBSCRIBE, "", 0 );
}

//! Esse método deve ser chamado em um loop infinito controlado.
//! O recebimento tratado aqui é não bloqueante
State InterfaceCore::receiveState( FieldTransformation userTransformation ){

	//! Recebendo informações via socket e atualizando o globalState
	zmq::message_t request;
	socket->recv( &request, 0 );
	std::string msg_str( static_cast<char*>(request.data()), request.size());
	globalState.ParseFromString( msg_str );

	return globalStateToState( globalState, userTransformation );
}

State InterfaceCore::globalStateToState(vss_state::Global_State _globalState, FieldTransformation userTransformation){
	State state;

	state.ball = ballStateToBall(_globalState.balls(0));
		
		for (int i = 0; i < 3; i++) {
			state.teamBlue[i] = robotStateToRobot(_globalState.robots_blue(i));
			state.teamYellow[i] = robotStateToRobot(_globalState.robots_yellow(i));
		}

		if (userTransformation == FieldTransformation::Flip180Degrees) {
			CoordinateTransformer transformState;
			state = transformState.spinField180Degrees(state);
		}
	return state;
}

Robot InterfaceCore::robotStateToRobot(vss_state::Robot_State robot_state) {
    Robot robot;

    robot.x = robot_state.pose().x();
    robot.y = robot_state.pose().y();
    robot.angle = robot_state.pose().yaw();
    
    robot.speedX = robot_state.v_pose().x();
    robot.speedY = robot_state.v_pose().y();
    robot.speedAngle = robot_state.v_pose().yaw();

    return robot;
}

Ball InterfaceCore::ballStateToBall(vss_state::Ball_State ball_state) {
    Ball ball;

    ball.x = ball_state.pose().x();
    ball.y = ball_state.pose().y();

    ball.speedX = ball_state.v_pose().x();
    ball.speedY = ball_state.v_pose().y();
    
    return ball;
}