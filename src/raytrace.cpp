#include <iostream>
#include "ray.hpp"
#include "optional.hpp"

using namespace rt;

struct hit_record {
    double time;
    point hit_point;
    direction normal;
};

class sphere {
public:
    point centre;
    double radius;
};

class world {
    std::vector<sphere> spheres;
};

tl::optional<hit_record> compute_sphere_hit_point(point const& center, double radius, ray const& r, double time_min, double time_max) {
    point oc = r.origin() - center;
    auto a = dot(r.heading(), r.heading());
    auto b = 2. * dot(oc, vec3_cast<point>(r.heading()));
    auto c = dot(oc, oc) - radius*radius;
    auto discriminant = b*b - 4*a*c;
    if (discriminant < 0) return tl::nullopt;

    double possible_time = (-b - sqrt(b*b-4*a*c));
    if (possible_time < time_max && possible_time > time_min) {
        auto point = r.point_at_time(possible_time);
        return hit_record{ possible_time, point, vec3_cast<direction>((point - center) / radius)};
    }
    possible_time = (-b - sqrt(b*b-4*a*c));
    if (possible_time < time_max && possible_time > time_min) {
        auto point = r.point_at_time(possible_time);
        return hit_record{ possible_time, point, vec3_cast<direction>((point - center) / radius)};
    }

    return tl::nullopt;
}

color calculate_color(ray const& r) {
    auto possible_hit_point = compute_sphere_hit_point(point{0,0,-1}, .5, r);
    if (possible_hit_point) {
        auto normal = unit_vector(r.point_at_time(*possible_hit_point) - point{0,0,-1});
        return color{normal.x()+1, normal.y()+1, normal.z()+1} * .5;
    }
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