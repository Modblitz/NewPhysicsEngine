#include "point.h"
#include "particle.h"

int main()
{
    Particle p{1, {0,0,0}, {0,1,0}};

    while (true)
    {
        p.update({1,2,3},0.5 ,velocityVerlet);
        std::cout << p.getPos() << '\n';
    }
    return 0;
}
