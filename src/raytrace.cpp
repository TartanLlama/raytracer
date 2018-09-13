#include <iostream>
#include "ray.hpp"

using namespace rt;

bool hit_sphere(point const& center, double radius, ray const& r) {
    point oc = r.origin() - center;
    auto a = dot(r.heading(), r.heading());
    auto b = 2. * dot(oc, vec3_cast<point>(r.heading()));
    auto c = dot(oc, oc) - radius*radius;
    auto discriminant = b*b - 4*a*c;
    return discriminant > 0;
}

color calculate_color(ray const& r) {
    auto unit_direction = unit_vector(r.heading());
    double t = 0.5 * (unit_direction.y() + 1.0);
    auto white = color{1,1,1};
    auto blue =  color{.5,.7,1};
    return  white * (-t + 1.0) + (blue * t);
}

int main() {
    size_t nx = 200;
    size_t ny = 100;
    
    std::cout << "P3\n" << nx << " " << ny << "\n255\n";

    point lower_left_corner{-2,-1,-1};
    point horizontal{4,0,0};
    point vertical{0,2,0};
    point origin{0,0,0};

    for (int j = ny-1; j >= 0; --j) {
        for (int i = 0; i < nx; ++i) {
            auto u = static_cast<double>(i) / nx;
            auto v = static_cast<double>(j) / ny;
            ray r{origin, vec3_cast<direction>(lower_left_corner + horizontal*u + vertical*v)};

            auto col = calculate_color(r);
            auto ir = static_cast<int>(255.99*col.r());
            auto ig = static_cast<int>(255.99*col.g());
            auto ib = static_cast<int>(255.99*col.b());

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
}