#ifndef PARTICLE_H
#define PARTICLE_H

#include <array>
#include <math.h>
#include "point.h"
#include <vector>

inline void velocityVerlet(double dt, Point& pos, Point& vel, Point& acc)
{
    pos = pos + vel*dt +0.5*acc*pow(dt,2);
    vel = vel+acc*dt;
}

class Particle
{
protected:
    double m_mass{};
    Point m_vel{};
    Point m_pos{};

public:
    Particle(double mass, Point&& pos, Point&& vel)
    :m_mass{mass}, m_pos{pos}, m_vel{vel}
    {}

    void update(const Point& force, double dt, void(*iterator)(double, Point&, Point&, Point&))
    {
        Point acc{force / m_mass};
        iterator(dt, m_pos, m_vel, acc);
    }

    Point& getPos() {return m_pos;}
    Point& getVel() {return m_vel;}

    double distanceFrom(Particle& p) const
    {
        return m_pos.distanceFrom(p.getPos());
    }

};

class Sphere : public Particle
{
protected:
    double m_radius{};
public:
    Sphere(double radius, double mass, Point&& pos, Point&& vel)
    : Particle{mass, pos, vel}, m_radius{radius}
    {}

    
};

#endif
