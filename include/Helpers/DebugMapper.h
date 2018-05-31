//
// Created by johnathan on 29/05/18.
//

#ifndef VSS_CORE_DEBUGMAPPER_H
#define VSS_CORE_DEBUGMAPPER_H

#include <Domain/Debug.h>
#include "debug.pb.h"

namespace vss {

    namespace DebugMapper {

        vss_debug::Global_Debug debugToGlobalDebug(Debug debug);
        void setupStepPoint(vss_debug::Pose *stepPose, Point point);
        void setupFinalPose(vss_debug::Pose *finalPose, Pose pose);
        void setupPath(vss_debug::Path *vssPath, Path path);
    }

}

#endif //VSS_CORE_DEBUGMAPPER_H
