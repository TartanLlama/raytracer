#pragma once

#include "vec3.hpp"

namespace rt {
class ray {
public:
    ray() = default;
    ray(point const& origin, direction const& heading) : origin_{origin}, heading_{heading} {}
    point const& origin() { return origin_; }
    direction const& heading() { return heading_; }
    point point_at_time(double t) const { return origin_ + vec3_cast<point>(heading_*t); }

private:
    point origin_;
    direction heading_;
};
}    
