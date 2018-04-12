/*
 * This file is part of the VSS-SDK project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#ifndef _INTERFACE_CORE_H_
#define _INTERFACE_CORE_H_

#include "sstream"
#include <iostream>
#include <string>
#include "unistd.h"

#include "State.h"
#include "FieldTransformation.h"
#include "CoordinateTransformer.h"

#include "zmq.hpp"       //! ZMQ: utilizado para comunicação via Sockets
#include <google/protobuf/text_format.h> //! Protobuf: utilizado para serialização/deserialização das mensagens
#include "protobuf/state.pb.h"      //! Protobuf: pacote gerado pelo state.proto
#include "protobuf/command.pb.h"      //! Protobuf: pacote gerado pelo command.proto
#include "protobuf/debug.pb.h"      //! Protobuf: pacote gerado pelo debug.proto
#include "protobuf/control.pb.h"      //! Protobuf: pacote gerado pelo debug.proto

using namespace std;

//! Essa classe define as interfaces utilizadas em todos os projetos do VSS-SDK, em outras palavras, todos os sockets abertos em todos os projetos estão aqui.
class InterfaceCore {
protected:

	//! Contexto do socket de envio de estados pelo VSS-Vision. E contexto do socket de recebimento de estados pelos VSS-SampleStrategys
	zmq::context_t *context;
	//! Socket de envio de estados pelo VSS-Vision. E socket de recebimento de estados pelos VSS-SampleStrategys
	zmq::socket_t *socket;
	
	//! Pacote de estados (Utilizado pelo VSS-Simulator e VSS-Vision, para enviar informações do campo) (Utilizado também pelo VSS-Viewer, para desenhar a estado do jogo e pelo VSS-SampleStrategy para construir-se uma estratégia)
	vss_state::Global_State globalState;

	//! Endereço mulsticast do recebimento dos estados por parte do VSS-Viewer e VSS-SampleStrategys
	string addr_client_multicast;


public:
	//! Construtor DEFAULT
	InterfaceCore();

	//! Método responsável por criar o socket de recebimento de estados em VSS-SampleStrategys
	void createSocketReceiveState( string addr_client_multicast = "tcp://localhost:5555" );
	//! Método responsável por receber um novo estado em VSS-SampleStrategys
	vss::State receiveState(FieldTransformation);
	
	//! Método responsável por converter um Ball_State em Ball
	vss::Ball ballStateToBall(vss_state::Ball_State);
	//! Método responsável por converter um Robot_State em Robot
	vss::Robot robotStateToRobot(vss_state::Robot_State);
	//! Método responsável por converter um Global_State em State
	vss::State globalStateToState(vss_state::Global_State, FieldTransformation);	
};

#endif // _INTERFACE_H_
