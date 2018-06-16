//
// Created by johnathan on 09/06/18.
//

#ifndef VSS_CORE_VSSLIB_H
#define VSS_CORE_VSSLIB_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Communications/CommandReceiver.h"
#include "Communications/CommandSender.h"
#include "Communications/ControlReceiver.h"
#include "Communications/ControlSender.h"
#include "Communications/DebugReceiver.h"
#include "Communications/DebugSender.h"
#include "Communications/StateReceiver.h"
#include "Communications/StateSender.h"
#include "Domain/Ball.h"
#include "Domain/Command.h"
#include "Domain/Constants.h"
#include "Domain/Control.h"
#include "Domain/Debug.h"
#include "Domain/FieldTransformationType.h"
#include "Domain/Path.h"
#include "Domain/Point.h"
#include "Domain/Pose.h"
#include "Domain/Robot.h"
#include "Domain/State.h"
#include "Domain/TeamType.h"
#include "Domain/WheelsCommand.h"
#include "Helpers/CommandMapper.h"
#include "Helpers/ControlMapper.h"
#include "Helpers/CoordinateTransformer.h"
#include "Helpers/DebugMapper.h"
#include "Helpers/DomainRandomizer.h"
#include "Helpers/Math.h"
#include "Helpers/StateMapper.h"
#include "Interfaces/ICommandReceiver.h"
#include "Interfaces/ICommandSender.h"
#include "Interfaces/IControlReceiver.h"
#include "Interfaces/IControlSender.h"
#include "Interfaces/IDebugReceiver.h"
#include "Interfaces/IDebugSender.h"
#include "Interfaces/IStateReceiver.h"
#include "Interfaces/IStateSender.h"
#include "command.pb.h"
#include "control.pb.h"
#include "debug.pb.h"
#include "interface.h"
#include "state.pb.h"

#ifdef __cplusplus
}
#endif

#endif //VSS_CORE_VSSLIB_H
