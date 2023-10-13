#pragma once

#include <Physics/types.hpp>

#include <iostream>

namespace Physics::SolarSystemObjects
{
    void print_data_info()
    {
        std::cout << "Data from https://ssd.jpl.nasa.gov/horizons\n";
        std::cout << "Ephemeris at 2460230.500000000 = A.D. 2023-Oct-13 00:00:00.0000 TDB\n";
    }
    
    const ::Physics::Types::NewtonianBody Sun{
        1.988500E+30,
        ::Physics::Types::Vec3{-1.246248960614091E+09, -3.459668336347048E+08, 3.192221888911456E+07},
        ::Physics::Types::Vec3{ 7.166809761243007E-06, -1.345351741038424E-05, -5.068509150256938E-08}
    };

    const ::Physics::Types::NewtonianBody Mercury{
        3.302E+23,
        ::Physics::Types::Vec3{-5.902744699969558E+10, -4.536055832029232E+08,  5.323064182640486E+09},
        ::Physics::Types::Vec3{-1.003577468277974E+04, -4.663462219350487E+04, -2.888798294669400E+03}
    };

    const ::Physics::Types::NewtonianBody Venus{
        4.8685E+24,
        ::Physics::Types::Vec3{ 5.825393718452090E+10, 8.978009624802722E+10, -2.163543284069147E+09},
        ::Physics::Types::Vec3{-2.932862622003346E+04, 1.912758405272881E+04,  1.955512553125713E+03}
    };

    const ::Physics::Types::NewtonianBody Earth{
        5.97219E+24,
        ::Physics::Types::Vec3{ 1.398585870833457E+11, 4.843677120719687E+10,  2.809895487007126E+07},
        ::Physics::Types::Vec3{-1.021195712408226E+04, 2.803992876121535E+04, -5.220708247932748E-07}
    };

    const ::Physics::Types::NewtonianBody Mars{
        6.4171E+23,
        ::Physics::Types::Vec3{-1.895647268701857E+11, -1.436071869857193E+11,  1.648883072371364E+09},
        ::Physics::Types::Vec3{ 1.558419673326580E+04, -1.722700899344684E+04, -7.428990743111568E-04}
    };

    const ::Physics::Types::NewtonianBody Jupiter{
        1.89818722E+27,
        ::Physics::Types::Vec3{ 5.826747457163857E+11, 4.599651166212387E+11, -1.494432580434754E+10},
        ::Physics::Types::Vec3{-8.241199947032024E+03, 1.087505145404245E+04,  1.393231631150393E-04}
    };

    const ::Physics::Types::NewtonianBody Saturn{
        5.6834E+26,
        ::Physics::Types::Vec3{1.321431017060648E+12, -6.173361437917207E+11, -4.187845963393810E+10},
        ::Physics::Types::Vec3{3.549563801854642E+03,  8.731782574734982E+03, -2.926711520784573E-04}
    };

    const ::Physics::Types::NewtonianBody Uranus{
        8.6813E+25,
        ::Physics::Types::Vec3{ 1.871362424559545E+12, 2.260921881491668E+12, -1.584674498980212E+10},
        ::Physics::Types::Vec3{-5.296130558164179E+03, 4.024911046457116E+03,  8.370658735078651E-05}
    };

    const ::Physics::Types::NewtonianBody Neptune{
        1.02409E+26,
        ::Physics::Types::Vec3{4.461089451523262E+12, -3.060641860424699E+11, -9.650729835591713E+10},
        ::Physics::Types::Vec3{3.360812244993985E-04,  5.454752374765219E+03, -1.200831816935859E-04}
    };

    const ::Physics::Types::NewtonianBody Pluto{
        1.307E+22,
        ::Physics::Types::Vec3{2.539670413271709E+12, -4.549218823393610E+12, -2.478285310759344E+11},
        ::Physics::Types::Vec3{4.900045529504120E+03,  1.477922051040077E+03, -1.564663427147844E+03}
    };

    const ::Physics::Types::SystemState SolarSystem{
        0.0,        
        {
            Sun,
            Mercury,
            Venus,
            Earth,
            Mars,
            Jupiter,
            Saturn,
            Uranus,
            Neptune,
            Pluto
        }
    };
}