#pragma once

#include <vector>

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
};

Vec3 operator*(double lhs, const Vec3& rhs);

struct NewtonianBody
{
    double mass;
    Vec3 position;
    Vec3 velocity;

    NewtonianBody operator*(double rhs) const;
    NewtonianBody operator/(double rhs) const;
    NewtonianBody operator+(const NewtonianBody& rhs) const;
};

struct SystemState
{
    double time;
    std::vector<NewtonianBody> bodies;

    SystemState operator*(double rhs) const;
    SystemState operator/(double rhs) const;
    SystemState operator+(const SystemState& rhs) const;
};

}