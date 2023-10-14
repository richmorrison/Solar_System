#pragma once

#include <Physics/Types/Vec3.hpp>
#include <Physics/Types/NewtonianBody.hpp>
#include <Physics/Types/SystemState.hpp>

#include <vector>

namespace Physics::Newtonian
{

::Physics::Types::Vec3 gravitationalAcceleration(const std::vector<::Physics::Types::NewtonianBody> bodies, int iBody);

::Physics::Types::SystemState gradNewtonianStates(const ::Physics::Types::SystemState& state);

}