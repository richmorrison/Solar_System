#pragma once

#include <Physics/Types/Vec3.hpp>

#include <string>
#include <iostream>

namespace Physics::Types
{

struct NewtonianBody
{
    double mass;
    Vec3 position;
    Vec3 velocity;

    NewtonianBody operator*(double rhs) const;
    NewtonianBody operator/(double rhs) const;
    NewtonianBody operator+(const NewtonianBody& rhs) const;

    operator std::string() const {return std::string(position);}
};

std::ostream& operator<<(std::ostream& os, const NewtonianBody& body);

}