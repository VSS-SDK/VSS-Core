all:	
	protoc -I=. --cpp_out=cpp state.proto		
	protoc -I=. --cpp_out=cpp command.proto	
	protoc -I=. --cpp_out=cpp debug.proto		

	PATH="$HOME/.cargo/bin:$PATH"
	protoc --rust_out rust state.proto command.proto debug.proto