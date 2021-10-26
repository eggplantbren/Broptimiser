#include <iostream>
#include "Optimiser.h"

using namespace Broptimiser;


double trivial(const std::vector<double>& values)
{
    double tot = 0.0;
    for(double x: values)
        tot += -0.5*x*x;
    return tot;
}

int main()
{
    Tools::RNG rng;
    Optimiser optimiser(trivial, Particle(10, 12.3));

    return 0;
}
