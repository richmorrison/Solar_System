#include <Physics/newtonian.hpp>
#include <Physics/constants.hpp>

namespace Physics::Newtonian
{

::Physics::Types::Vec3 gravitationalAcceleration(const std::vector<::Physics::Types::NewtonianBody> bodies, int iBody)
{
    ::Physics::Types::Vec3 gravitationalAcceleration{0,0,0};
    
    const ::Physics::Types::NewtonianBody* self = &bodies[iBody];

    for(auto i=0; i<bodies.size(); i++)
    {
        if(i==iBody) continue;

        const ::Physics::Types::NewtonianBody* neighbour = &bodies[i];

        ::Physics::Types::Vec3 to_body = (neighbour->position - self->position).normalise();
        double distance = (neighbour->position - self->position).magnitude();
        gravitationalAcceleration += ::Physics::Constants::G*neighbour->mass/(distance*distance)*to_body;
    }

    return gravitationalAcceleration;
}

::Physics::Types::SystemState gradNewtonianStates(const ::Physics::Types::SystemState& state)
{
    ::Physics::Types::SystemState result;
    
    result.time = 1;

    for(auto iBody=0; iBody<state.bodies.size(); iBody++)
        result.bodies.push_back(::Physics::Types::NewtonianBody{0, state.bodies[iBody].velocity, gravitationalAcceleration(state.bodies, iBody)});
    
    return result;
}

}