#include <Physics/Types/Vec3.hpp>

#include <cmath>

namespace Physics::Types
{

Vec3 Vec3::operator*(double rhs) const
{
    return Vec3{x*rhs, y*rhs, z*rhs};
}

Vec3 Vec3::operator/(double rhs) const
{
    return Vec3{x/rhs, y/rhs, z/rhs};
}

Vec3 Vec3::operator+(const Vec3& rhs) const
{
    return Vec3{x+rhs.x, y+rhs.y, z+rhs.z};
}

Vec3 Vec3::operator-(const Vec3& rhs) const
{
    return *this+(rhs*-1);
}

Vec3& Vec3::operator+=(const Vec3& rhs)
{
    return *this = *this+rhs;
}

double Vec3::magnitude()
{
    return std::sqrt(x*x + y*y + z*z);
}

Vec3 Vec3::normalise()
{
    return *this/magnitude();
}

std::ostream& operator<<(std::ostream& os, const Vec3& vec)
{
    return os << std::string(vec);
}

Vec3 operator*(double lhs, const Vec3& rhs)
{
    return rhs*lhs;
}

}