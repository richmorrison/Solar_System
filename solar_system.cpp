#include <Numerics/ODEsolvers.hpp>
#include <Physics/newtonian.hpp>
#include <Physics/solar_system_objects.hpp>

#include <iostream>

std::vector<double> getDataPoints(unsigned int everyNseconds, unsigned int totalYears)
{
    std::vector<double> dataPoints;

    for(int i=0; i<=totalYears*365.25*24*60*60; i+=everyNseconds)
        dataPoints.push_back(i);
    
    return dataPoints;
}

void printSolution(std::vector<::Physics::Types::SystemState> solution)
{
    // t, sun_x, sun_y, sun_z, mercury_x, mercury_y, mercury_z ...

    for(auto i=0; i<solution.size(); i++) // For each timestep
    {
        std::cout << i;

        for(auto body=0; body<solution[i].bodies.size(); body++) // For each body, print x,y,z
        {
            std::cout
                << "\t" << solution[i].bodies[body].position.x
                << "\t" << solution[i].bodies[body].position.y
                << "\t" << solution[i].bodies[body].position.z;
        }
        std::cout << "\n";
    }

    return;
}

int main(void)
{
    ::Physics::SolarSystemObjects::print_data_info();
    
    // Plotting data every day for 10 years
    std::vector<double> dataPoints = getDataPoints(24*60*60, 10);

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
    printSolution(solution);

    return 0;
}