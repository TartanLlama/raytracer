#include <iostream>
#include "ray.hpp"

using namespace rt;

color calculate_color(ray const& r) {
    auto unit_direction = unit_vector(r.heading());
    double t = 0.5 * (unit_direction.y() + 1.0);
    return color{1,1,1} * (-t + 1.0) + color{.5,.7,1};
}

int main() {
    size_t nx = 200;
    size_t ny = 200;
    
    std::cout << "P3\n" << nx << " " << ny << "\n255\n";

    point lower_left_corner{-2,-1,-1};
    point horizontal{4,0,0};
    point vertical{0,2,0};
    point origin{0,0,0};

    
}