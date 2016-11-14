#!/bin/bash
#
# This file is part of the VSS-SDK project.
#
# This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
# v. 3.0. If a copy of the GPL was not distributed with this
# file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
#
	
protoc -I=. --cpp_out=cpp state.proto		
protoc -I=. --cpp_out=cpp command.proto	
protoc -I=. --cpp_out=cpp debug.proto		

PATH="$HOME/.cargo/bin:($PATH)"
protoc --rust_out rust state.proto command.proto debug.proto