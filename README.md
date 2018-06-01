# VSS-Core [![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)][gpl3] [![Build Status](https://travis-ci.org/SIRLab/VSS-Core.svg?branch=master)][travis]

[![Trello](https://img.shields.io/badge/Trello-SDK-blue.svg)][vss-sdk-trello]
[![Slack](https://img.shields.io/badge/Slack-Channel-551a8b.svg)][slack]

O VSS-Core é uma biblioteca open-source que faz parte do VSS-SDK.
Contém interfaces de comunicação entre os projetos do SDK, modelos que representam o domínio do problema de futebol de robôs e métodos uteis. Os pacotes traferam utilizando ZeroMQ e são serializados utilizando Protobuf.

Mais informações podem ser encontradas em [VSS-SDK][vss-sdk].

## Installation
```
$ sudo ./configure.sh
```

## Development
```
$ sudo ./configure.sh development
```
## Samples
C++ using the VSS-Core: [SampleCpp][samplecpp]


#License

This code is licensed under the [GNU GENERAL PUBLIC LICENSE Version 3][gpl3], of which a textual copy is available at [LICENSE.txt](LICENSE.txt).

You are allowed and encouraged to use this software on robotics competitions.  If you do, please let us know.


[gpl3]: http://www.gnu.org/licenses/gpl-3.0/
[vss-sdk]: http://sirlab.github.io/VSS-SDK
[samplecpp]: https://github.com/SIRLab/VSS-SampleCpp
[travis]: https://travis-ci.org/SIRLab/VSS-Core
[vss-sdk-trello]: https://trello.com/b/b4dVV6ug/vss-sdk
[slack]: https://vss-sdk.slack.com
