//
// Created by johnathan on 31/05/18.
//

#include "cmath"
#include "Helpers/Math.h"

namespace vss {

    namespace Math {

        float distance( const vss::Point &t1, const vss::Point &t2 ){
            return std::sqrt(((t1.x - t2.x) * (t1.x - t2.x)) + ((t1.y - t2.y) * (t1.y - t2.y)));
        }

    }

}