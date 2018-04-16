#ifndef _COORDINATE_TRANSFORMER_H_
#define _COORDINATE_TRANSFORMER_H_

#include "State.h"

namespace vss {

    class CoordinateTransformer {
    public:
        Ball spin180Degrees(Ball ball);
        Robot spin180Degrees(Robot robot);
        State spinField180Degrees(State state);
    };

}

#endif