#include <Physics/Types/SystemState.hpp>

namespace Physics::Types
{

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

std::ostream& operator<<(std::ostream& os, const SystemState& state)
{
    return os << std::string(state);
}

}