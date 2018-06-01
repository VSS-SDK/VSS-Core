# VSS-Core [![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)][gpl3] [![Build Status](https://travis-ci.org/SIRLab/VSS-Core.svg?branch=master)][travis]


[![Trello](https://img.shields.io/badge/Trello-SDK-blue.svg)][vss-sdk-trello]
[![Slack](https://img.shields.io/badge/Slack-Channel-551a8b.svg)][slack]

O VSS-Core é uma biblioteca open-source que faz parte do VSS-SDK.
Contém a parte de comunicação entre os projetos utilizando as 
bibliotecas Google Protocols Buffere ZeroMQ para realizar. Também guarda classes,
estruturas e enums úteis.


Mais informações podem ser encontradas em [VSS-SDK][vss-sdk].

## Installation
```
$ sudo ./configure.sh
```

## Development
```
$ sudo ./configure.sh development
```

## Protos

### Field state

```protobuf
message Global_State{
  optional uint32       id = 1;
  optional bool         origin = 2;
  repeated Ball_State   balls = 3;
  repeated Robot_State  robots_yellow = 4;
  repeated Robot_State  robots_blue = 5;
  optional uint32       paused = 6;
  optional uint32       time = 7;
}
```

### Robots commands

```protobuf
message Global_Commands{
	optional uint32         id = 1;
	optional bool           is_team_yellow = 2;
	repeated Robot_Command  robot_commands = 3;
}
```

### Debug information

```protobuf
message Global_Debug{
    repeated Pose   step_poses  = 1;
    repeated Pose   final_poses = 2;
    repeated Path   paths       = 3;
}
```

### User control

```protobuf
message User_Control{
    optional bool paused = 1;
    optional Pose new_ball_pose = 2;
    repeated Pose new_robots_blue_pose = 3;
    repeated Pose new_robots_yellow_pose = 4;
}
```

## Samples
C++ using the VSS-Core: [SampleCpp][samplecpp]


License
-------

This code is licensed under the [GNU GENERAL PUBLIC LICENSE Version 3][gpl3], of which a textual copy is available at [LICENSE.txt](LICENSE.txt).

You are allowed and encouraged to use this software on robotics competitions.  If you do, please let us know.


[gpl3]: http://www.gnu.org/licenses/gpl-3.0/
[vss-sdk]: http://sirlab.github.io/VSS-SDK
[samplecpp]: https://github.com/SIRLab/VSS-SampleCpp
[travis]: https://travis-ci.org/SIRLab/VSS-Core
[vss-sdk-trello]: https://trello.com/b/b4dVV6ug/vss-sdk
[slack]: https://vss-sdk.slack.com
