#ifndef FIELD_TRANSFORMATION_H_
#define FIELD_TRANSFORMATION_H_

#include "State.h"

class FieldTransformation {

private:
    static Ball spin180Degrees(Ball robot);
    static Robot spin180Degrees(Robot robot);
    
public:
    static State spinField180Degrees(State);    
    enum Transformation {None = 0, Flip180Degrees = 1};
};

#endif