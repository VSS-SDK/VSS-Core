all:	
	protoc -I=. --cpp_out=cpp-interface state.proto		
	protoc -I=. --cpp_out=cpp-interface command.proto	
	protoc -I=. --cpp_out=cpp-interface debug.proto		

	PATH="$HOME/.cargo/bin:$PATH"
	protoc --rust_out rust-interface state.proto command.proto debug.proto