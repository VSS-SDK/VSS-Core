//
// Created by johnathan on 30/05/18.
//

#include <Domain/Point.h>

namespace vss {

    Point::Point() {
        x = 0;
        y = 0;
    }

    Point::Point(float x, float y) {
        this->x = x;
        this->y = y;
    }

    std::ostream &operator<<(std::ostream &os, const Point &point) {
        return os << "Point(" << point.x << ", " << point.y << ")";
    }

}

