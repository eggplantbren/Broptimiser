#include <iomanip>
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

    for(int i=0; i<1000; ++i)
        optimiser.explore(rng, 100);

    auto best = optimiser.get_best_params();
    std::cout << "Best parameter vector: " << std::endl;
    std::cout << std::setprecision(12);
    for(double x: best)
        std::cout << x << ' ';
    std::cout << std::endl;

    return 0;
}
