#include <Physics/Types/NewtonianBody.hpp>

namespace Physics::Types
{

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

std::ostream& operator<<(std::ostream& os, const NewtonianBody& body)
{
    return os << std::string(body);
}

}