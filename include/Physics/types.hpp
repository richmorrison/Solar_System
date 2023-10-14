#pragma once

#include <vector>
#include <string>

namespace Physics::Types
{

struct Vec3
{
    double x;
    double y;
    double z;

    Vec3 operator*(double rhs) const;
    Vec3 operator/(double rhs) const;

    Vec3 operator+(const Vec3& rhs) const;
    Vec3 operator-(const Vec3& rhs) const;
    Vec3& operator+=(const Vec3& rhs);

    double magnitude();
    Vec3 normalise();

    operator std::string() const {return std::to_string(x)+"\t"+std::to_string(y)+"\t"+std::to_string(z);}

    friend std::ostream& operator<<(std::ostream& os, const Vec3& vec) { return os << std::string(vec); }
};

Vec3 operator*(double lhs, const Vec3& rhs);

struct NewtonianBody
{
    double mass;
    Vec3 position;
    Vec3 velocity;

    NewtonianBody operator*(double rhs) const;
    NewtonianBody operator/(double rhs) const;
    NewtonianBody operator+(const NewtonianBody& rhs) const;

    operator std::string() const {return std::string(position);}

    friend std::ostream& operator<<(std::ostream& os, const NewtonianBody& body) { return os << std::string(body); }
};

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

    friend std::ostream& operator<<(std::ostream& os, const SystemState& state) { return os << std::string(state); }
};

}