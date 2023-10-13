#include <Physics/types.hpp>

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

Vec3 operator*(double lhs, const Vec3& rhs)
{
    return rhs*lhs;
}

NewtonianBody NewtonianBody::operator*(double rhs) const
{
    return NewtonianBody{mass*rhs, position*rhs, velocity*rhs};
}

NewtonianBody NewtonianBody::operator/(double rhs) const
{
    return NewtonianBody{mass/rhs, position/rhs, velocity/rhs};
}

NewtonianBody NewtonianBody::operator+(const NewtonianBody& rhs) const
{
    return NewtonianBody{mass+rhs.mass, position+rhs.position, velocity+rhs.velocity};
}

SystemState SystemState::operator*(double rhs) const
{
    SystemState ret;
    ret.time = time*rhs;
    for(auto i=0; i<bodies.size(); i++) ret.bodies.push_back(bodies[i]*rhs);
    return ret;
};

SystemState SystemState::operator/(double rhs) const
{
    SystemState ret;
    ret.time = time/rhs;
    for(auto i=0; i<bodies.size(); i++) ret.bodies.push_back(bodies[i]/rhs);
    return ret;
};

SystemState SystemState::operator+(const SystemState& rhs) const
{
    SystemState ret;
    ret.time = time + rhs.time;
    for(auto i=0; i<bodies.size(); i++) ret.bodies.push_back(bodies[i]+rhs.bodies[i]);
    return ret;
}

}