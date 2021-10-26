#include <iostream>
#include "Particle.h"

using namespace Broptimiser;

int main()
{
    Tools::RNG rng;
    Particle p(10, rng);
    std::cout << p << std::endl;

    return 0;
}
