#pragma once

#include <string>

namespace Physics::Types
{

struct Vec3
{
    double x;
    double y;
    double z;

    Vec3 operator*(double rhs) const;
    Vec3 operator/(double rhs) const;

    Vec3 operator+(const Vec3& rhs) const;
    Vec3 operator-(const Vec3& rhs) const;
    Vec3& operator+=(const Vec3& rhs);

    double magnitude();
    Vec3 normalise();

    operator std::string() const {return std::to_string(x)+"\t"+std::to_string(y)+"\t"+std::to_string(z);}
};

Vec3 operator*(double lhs, const Vec3& rhs);

std::ostream& operator<<(std::ostream& os, const Vec3& vec);

}