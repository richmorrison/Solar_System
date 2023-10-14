#include <Numerics/ODEsolvers.hpp>
#include <Physics/newtonian.hpp>
#include <Physics/solar_system_objects.hpp>

#include <iostream>

std::vector<double> defineDataPoints(unsigned int everyNseconds, unsigned int totalYears)
{
    std::vector<double> dataPoints;

    for(int i=0; i<=totalYears*365.25*24*60*60; i+=everyNseconds)
        dataPoints.push_back(i);
    
    return dataPoints;
}

int main(void)
{
    ::Physics::SolarSystemObjects::print_data_info();
    
    // Plotting data every day for 10 years
    std::vector<double> dataPoints = defineDataPoints(24*60*60, 10);

    // Solve for orbital positions

    std::vector<::Physics::Types::SystemState> solution = ::Numerics::ODEsolvers::solve_ode<::Physics::Types::SystemState>(
        ::Numerics::ODEsolvers::runge_kutta,                                                // Numerical method
        ::Physics::SolarSystemObjects::SolarSystem,                                         // State with main solar system bodies
        ::Physics::Newtonian::gradNewtonianStates,                                          // Apply Newtonian Physics
        60*60,                                                                              // 1 hour timesteps
        dataPoints,                                                                         // Reportable times
        [](double target, const ::Physics::Types::SystemState& s){return s.time>=target;}   // Reportable time reached
    );

    // Print solution
    for(auto state : solution)
    {
        std::cout << state << "\n";
    }

    return 0;
}