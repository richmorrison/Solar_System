#pragma once

#include <Physics/Types/NewtonianBody.hpp>

#include <vector>
#include <string>

namespace Physics::Types
{

struct SystemState
{
    double time;
    std::vector<NewtonianBody> bodies;

    SystemState operator*(double rhs) const;
    SystemState operator/(double rhs) const;
    SystemState operator+(const SystemState& rhs) const;

    operator std::string() const {
        std::string str = std::to_string(time);
        for(auto body : bodies) str+=std::string(body)+"\t";
        return str;
    }
};

std::ostream& operator<<(std::ostream& os, const SystemState& state);

}