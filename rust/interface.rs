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

use zmq::{Context, SUB, PAIR};
use protobuf::{parse_from_bytes, RepeatedField, Message};

use state::Global_State;
use command::{Global_Commands, Robot_Command};
use debug::Global_Debug;

#[allow(dead_code)]
pub struct Interface {
    context_recv: Context,
    context_send: Context,
    global_state: Global_State,
    global_commands: Global_Commands,
    global_debug: Global_Debug,
}

impl Interface {
    pub fn new() -> Interface {
        Interface {
            context_recv: Context::new(),
            context_send: Context::new(),
            global_state: Global_State::new(),
            global_commands: Global_Commands::new(),
            global_debug: Global_Debug::new(),
        }
    }
}
