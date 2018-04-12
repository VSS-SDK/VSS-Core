#ifndef _COORDINATE_TRANSFORMER_H_
#define _COORDINATE_TRANSFORMER_H_

#include "State.h"

class CoordinateTransformer {

public:
    vss::Ball spin180Degrees(vss::Ball ball);
    vss::Robot spin180Degrees(vss::Robot robot);
    vss::State spinField180Degrees(vss::State state);
};
 
#endif