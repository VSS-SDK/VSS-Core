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
    }
}

#endif //VSS_CORE_DEBUGMAPPER_H
