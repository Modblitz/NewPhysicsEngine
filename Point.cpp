#include <iostream>

class Point
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point(double x, double y, double z)
    : m_x{x}, m_y{y}, m_z{z}
    {}

    friend std::ostream& operator<<(std::ostream out, const Point& p)
    {
        out << '(' << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
        return out;
    }
}
