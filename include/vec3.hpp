#include <cmath>
#include <array>

namespace rt
{
template <class T, class NamedTag = struct vec3_default_tag>
class vec3
{
  public:
    vec3() = default;
    vec3(T a, T b, T c) : data_{a, b, c} {}

    T &x() { return data_[0]; }
    T const &x() const { return data_[0]; }
    T &y() { return data_[1]; }
    T const &y() const { return data_[1]; }
    T &z() { return data_[2]; }
    T const &z() const { return data_[2]; }

    T &r() { return data_[0]; }
    T const &r() const { return data_[0]; }
    T &g() { return data_[1]; }
    T const &g() const { return data_[1]; }
    T &b() { return data_[2]; }
    T const &b() const { return data_[2]; }

    vec3 operator-() const { return vec3{-data_[0], -data_[1], -data_[2]}; }
    T &operator[](std::size_t n) { return data_[n]; }
    T const &operator[](std::size_t n) const { return data_[n]; }

    T length() const {
        return std::sqrt(x()*x() + y()*y() + z()*z());
    }

    friend T dot(vec3 const &lhs, vec3 const &rhs)
    {
        return lhs.x() * rhs.x() + lhs.y() * rhs.y() + lhs.z() * rhs.z();
    }

    vec3 &operator+=(vec3 const &rhs)
    {
        data_[0] += rhs[0];
        data_[1] += rhs[1];
        data_[2] += rhs[2];
        return *this;
    }
    vec3 &operator-=(vec3 const &rhs)
    {
        data_[0] -= rhs[0];
        data_[1] -= rhs[1];
        data_[2] -= rhs[2];
        return *this;
    }
    vec3 &operator*=(vec3 const &rhs)
    {
        data_[0] *= rhs[0];
        data_[1] *= rhs[1];
        data_[2] *= rhs[2];
        return *this;
    }
    vec3 &operator/=(vec3 const &rhs)
    {
        data_[0] /= rhs[0];
        data_[1] /= rhs[1];
        data_[2] /= rhs[2];
        return *this;
    }
    vec3 &operator+=(T rhs)
    {
        data_[0] += rhs;
        data_[1] += rhs;
        data_[2] += rhs;
        return *this;
    }
    vec3 &operator-=(T rhs)
    {
        data_[0] -= rhs;
        data_[1] -= rhs;
        data_[2] -= rhs;
        return *this;
    }
    vec3 &operator*=(T rhs)
    {
        data_[0] *= rhs;
        data_[1] *= rhs;
        data_[2] *= rhs;
        return *this;
    }
    vec3 &operator/=(T rhs)
    {
        data_[0] /= rhs;
        data_[1] /= rhs;
        data_[2] /= rhs;
        return *this;
    }

    friend vec3 operator+(vec3 const &lhs, vec3 const &rhs)
    {
        auto ret = lhs;
        ret += rhs;
        return ret;
    }
    friend vec3 operator-(vec3 const &lhs, vec3 const &rhs)
    {
        auto ret = lhs;
        ret -= rhs;
        return ret;
    }
    friend vec3 operator*(vec3 const &lhs, vec3 const &rhs)
    {
        auto ret = lhs;
        ret *= rhs;
        return ret;
    }
    friend vec3 operator/(vec3 const &lhs, vec3 const &rhs)
    {
        auto ret = lhs;
        ret /= rhs;
        return ret;
    }
    friend vec3 operator+(vec3 const &lhs, T rhs)
    {
        auto ret = lhs;
        ret += rhs;
        return ret;
    }
    friend vec3 operator-(vec3 const &lhs, T rhs)
    {
        auto ret = lhs;
        ret -= rhs;
        return ret;
    }
    friend vec3 operator*(vec3 const &lhs, T rhs)
    {
        auto ret = lhs;
        ret *= rhs;
        return ret;
    }
    friend vec3 operator/(vec3 const &lhs, T rhs)
    {
        auto ret = lhs;
        ret /= rhs;
        return ret;
    }

    friend vec3 unit_vector(vec3 const &v) { return v / v.length(); }

  private:
    std::array<T, 3> data_;
};

template <class To, class T, class Tag>
To vec3_cast(vec3<T, Tag> const &from)
{
    return To{from[0], from[1], from[2]};
}

using point = vec3<double, struct point_tag>;
using direction = vec3<double, struct direction_tag>;
using color = vec3<double, struct color_tag>;
} // namespace rt
