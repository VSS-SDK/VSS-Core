VSS-Interface
-------------
[![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)][gpl3]

Mais informações podem ser encontradas em [VSS-SDK][vss-sdk].

```
VSS-Interface
|---protos.make
|---state.proto
|---debug.proto
|---command.proto
|---|cpp
	|---interface.h
	|---interface.cpp
	|---|protos
		|---state.pb.h
		|---state.pb.cc
		|---debug.pb.h
		|---debug.pb.cc
		|---command.pb.h
		|---command.pb.cc
|---|java
|---|rust
	|---mod.rs
	|---state.rs
	|---debug.rs
	|---command.rs
```

License
-------

This code is licensed under the [GNU GENERAL PUBLIC LICENSE Version 3][gpl3], of which a textual copy is available at [LICENSE.txt](LICENSE.txt).

You are allowed and encouraged to use this software on the IEEE Very Small Size Soccer competitions.  If you do, please let us know.


[gpl3]: http://www.gnu.org/licenses/gpl-3.0/
[vss-sdk]: http://sirlab.github.io/VSS-SDK