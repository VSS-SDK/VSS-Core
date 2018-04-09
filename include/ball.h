#ifndef _BALL_H_
#define _BALL_H_

#include "object.h"
#include "state.pb.h"

class Ball : public Object {

public:
    Ball();
    Ball(vss_state::Ball_State);
    void ballStateToBall(vss_state::Ball_State);
};
 
#endif