/*
 * This file is part of the VSS-SDK project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

extern crate zmq;
extern crate protobuf;

pub mod state;
pub mod command;
pub mod debug;

use std::str;

use zmq::{Context, Socket, SUB, PAIR};
use protobuf::{parse_from_bytes, Message};

use state::Global_State;
use command::Global_Commands;
use debug::Global_Debug;

#[allow(dead_code)]
pub enum Team {
    TEAM1,
    TEAM2,
}

#[allow(dead_code)]
pub struct Interface {
    context: Context,
    socket: Socket,
    team: Team,
}

impl Interface {
    pub fn new() -> Interface {
        Interface {
            context: Context::new(),
            socket: Context::new().socket(SUB).unwrap(),
            team: Team::TEAM1,
        }
    }    

    pub fn create_socket_receive_state(&mut self) -> () {
        self.socket = self.context.socket(SUB).unwrap();
        assert!(self.socket.connect("tcp://localhost:5555").is_ok());
        let filter = "".to_string();
        assert!(self.socket.set_subscribe(filter.as_bytes()).is_ok());
    }

    pub fn create_socket_send_commands(&mut self, team: Team) -> () {
        self.socket = self.context.socket(PAIR).unwrap();

        match team {
            Team::TEAM1 => assert!(self.socket.connect("tcp://localhost:5556").is_ok()),
            Team::TEAM2 => assert!(self.socket.connect("tcp://localhost:5557").is_ok()),
        }
    }

    pub fn create_socket_send_debug(&mut self, team: Team) -> () {
        self.socket = self.context.socket(PAIR).unwrap();

        match team {
            Team::TEAM1 => assert!(self.socket.connect("tcp://localhost:5558").is_ok()),
            Team::TEAM2 => assert!(self.socket.connect("tcp://localhost:5559").is_ok()),
        }
    }

    pub fn receive_state(&mut self) -> Global_State {
        let bytes_state = self.socket.recv_bytes(0).unwrap();
        let global_state = parse_from_bytes::<Global_State>(&bytes_state).unwrap();
        return global_state;
    } 

    pub fn send_commands(&mut self, global_commands: Global_Commands) -> () {
        let bytes_commands = global_commands.write_to_bytes().unwrap();
        let string_cmd = str::from_utf8(&bytes_commands).unwrap();
        self.socket.send_str(string_cmd, 0).unwrap();
    }

    pub fn send_debug(&mut self, global_debug: Global_Debug) -> () {
        let bytes_debug = global_debug.write_to_bytes().unwrap();
        let string_cmd = str::from_utf8(&bytes_debug).unwrap();
        self.socket.send_str(string_cmd, 0).unwrap();
    }
}
