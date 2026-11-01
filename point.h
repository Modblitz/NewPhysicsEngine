#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>

class Point
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point() = default;

    Point(double x, double y, double z)
    : m_x{x}, m_y{y}, m_z{z}
    {}

    friend std::ostream& operator<<(std::ostream& out, const Point& p)
    {
        out << '(' << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
        return out;
    };

    Point operator+(const Point& p) const {return {m_x + p.m_x, m_y + p.m_y, m_z + p.m_z};}
    Point operator-() const {return {-m_x, -m_y, -m_z};}
    Point operator-(const Point& p) const {return  {m_x - p.m_x, m_y - p.m_y, m_z - p.m_z};}
    Point operator/(const double div) const {return {m_x/div, m_y/div, m_z/div};}
    friend  Point operator*(const Point& p, const double mult)  {return {p.m_x*mult, p.m_y*mult, p.m_z*mult};}
    friend  Point operator*(const double mult, const Point& p)  {return p*mult;}

    double getx() const {return m_z;}
    double gety() const {return m_y;}
    double getz() const {return m_z;}

    double distanceFrom(const Point& p) const
    {
        return std::sqrt(pow(m_x-p.m_x, 2) + pow(m_y-p.m_y, 2) + pow(m_z-p.m_z, 2));
    }
};
#endif
