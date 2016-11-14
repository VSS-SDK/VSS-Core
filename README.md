# VSS-Interface

[![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)][gpl3]

Mais informações podem ser encontradas em [VSS-SDK][vss-sdk].

## State

```protobuf
message Global_State{
  optional uint32       id = 1;               //! ID da mensagem, pode ser enviado como contra-prova para verificar se a comunicação está sincronizada. Sende este o único valor OPICIONAL
  optional bool			origin = 2;		  	  //! Booleano que define a origem da mensagem. Caso TRUE a mensagem vem do VSS-Vision, caso FALSE a mensagem vem do VSS-Simulator
  repeated Ball_State   balls = 3;            //! Lista dinâmica de bolas. Esta parte é definida dinâmicamente, pois podem existir situações indesejadas onde mais de uma bola está presente no ambiente
  repeated Robot_State  robots_yellow = 4;    //! Lista dinâmica de robôs amarelos. Em geral sempre são enviados 3 robôs.
  repeated Robot_State  robots_blue = 5;      //! Lista dinâmica de robôs azuis. Em geral sempre são enviados 3 robôs.
  optional uint32       situation = 6;        //! Situação em que a partida se encontra, será utilizado no futuro, para "obrigar" os robôs sempre a se reposicionarem autonomamente no campo
  optional uint32       time = 7;             //! Tempo: 1, 2, 3 ou 4
  optional uint32       goals_yellow = 8;     //! Quantidade de Gols do Time Amarelo
  optional uint32       goals_blue = 9;       //! Quantidade de Gols do Time Azul
  optional string       name_yellow = 10;     //! Quantidade de Gols do Time Amarelo
  optional string       name_blue = 11;       //! Quantidade de Gols do Time Azul
}
```

## Commands

```protobuf
message Global_Commands{
	optional uint32			id = 1;					//! ID da mensagem. Afim de ser utilizado como contra-prova para verificar se a comunicação está sincronizada
	optional bool			is_team_yellow = 2;		//! Booleano que define se o time é amarelo ou azul
	repeated Robot_Command	robot_commands = 3;		//! Lista dinâmica de comandos. Sendo sempre 3, devido a quantidade robôs
	optional uint32			situation = 4;			//! Situação em que se encontra o comando. No futuro os robôs serão posicionados autonomamente
	optional string			name = 5;				//! Nome do time
}
```

## Debug

```protobuf
message Global_Debug{
    repeated Pose   step_poses  = 1;    //! Lista dinâmica de vetores de movimentação. Sendo sempre 3, devido a quantidade de robôs de um time
    repeated Pose   final_poses = 2;    //! Lista dinâmica de poses futuras. Sendo sempre 3, devido a quantidade de robôs de um time
    repeated Path   paths       = 3;    //! Lista dinâmica de caminhos. Sendo sempre 3, devido a quantidade de robôs de um time
}
```

## Exemplos
Exemplo de como utilizar os protos em C++: [SampleCpp][samplecpp]

Exemplo de como utilizar os protos em Rust: [SampleRust][samplerust]

License
-------

This code is licensed under the [GNU GENERAL PUBLIC LICENSE Version 3][gpl3], of which a textual copy is available at [LICENSE.txt](LICENSE.txt).

You are allowed and encouraged to use this software on the IEEE Very Small Size Soccer competitions.  If you do, please let us know.


[gpl3]: http://www.gnu.org/licenses/gpl-3.0/
[vss-sdk]: http://sirlab.github.io/VSS-SDK
[samplecpp]: https://github.com/SIRLab/VSS-SampleCpp
[samplerust]: https://github.com/SIRLab/VSS-SampleRust