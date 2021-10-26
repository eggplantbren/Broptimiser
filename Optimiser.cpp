#include "Optimiser.h"
#include <iostream>

namespace Broptimiser
{

Optimiser::Optimiser(Function&& _function, Particle&& _particle)
:function(_function)
,particle(_particle)
,best(particle)
{
    function_evaluations.emplace(function(particle.get_values()));
    std::cout << "Initialised optimiser. All time high = ";
    std::cout << *function_evaluations.begin() << '.';
    std::cout << std::endl;
}

} // namespace
