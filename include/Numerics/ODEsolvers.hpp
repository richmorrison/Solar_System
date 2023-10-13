#pragma once

#include <vector>
#include <functional>

namespace Numerics::ODEsolvers
{

    template<class State>
    State runge_kutta(const State& state, double h, State (*grad)(const State& state) )
    {
        State k1 = grad(state);
        State k2 = grad(state+k1*h/2);
        State k3 = grad(state+k2*h/2);
        State k4 = grad(state+k3*h);

        return state + (k1 + k2*2 + k3*2 + k4) * h/6;
    }

    template<class State>
    State forward_euler(const State& state, double h, State (*grad)(const State& state) )
    {
        return state + grad(state)*h;
    }


    template <class State>
    std::vector<State> solve_ode(
        State (*method)(const State& state, double h, State (*grad)(const State& state) ),
        State initial,
        State (*grad)(const State& state),
        double h,
        std::vector<double> targets,
        std::function<bool(double, const State&)> reached_target
    )
    {
        std::vector<State> solution;
        
        State current = initial;
        
        for(auto t : targets)
        {

            while(!reached_target(t, current))
                current = method(current, h, grad);
            
            solution.push_back(current);
        }

        return solution;
    }


}