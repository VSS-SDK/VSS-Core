VSS-Interface
-------------
Interface que possibilita a comunicação entre os projetos do VSS-SDK.

```
VSS-Interface
|---protos.make
|---state.proto
|---debug.proto
|---command.proto
|---|cpp-interface
	|---interface.h
	|---interface.cpp
	|---|protos
		|---state.pb.h
		|---state.pb.cc
		|---debug.pb.h
		|---debug.pb.cc
		|---command.pb.h
		|---command.pb.cc
|---|java-interface
|---|rust-interface
	|---mod.rs
	|---state.rs
	|---debug.rs
	|---command.rs
```
