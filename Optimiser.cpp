#include "Optimiser.h"
#include <iostream>

namespace Broptimiser
{

Optimiser::Optimiser(Function&& _function, Particle&& _particle)
:function(_function)
,particle(_particle)
,all_time_high(particle, 0.0)
{
    double f = function(particle.get_values());
    std::get<1>(all_time_high) = f;
    f_to_target.emplace(f, 0.0);
    scan();

    std::cout << "Initialised optimiser. All time high = ";
    std::cout << f << '.';
    std::cout << std::endl;
}

void Optimiser::scan()
{
    int s = f_to_target.size();
    int i = 0;
    int distance;
    std::cout << "Scan:" << std::endl;
    for(auto it=f_to_target.begin(); it != f_to_target.end(); ++it)
    {
        auto& [key, value] = *it;
        distance = s - i - 1; // At least 0
        value = -0.5*log(1.0 + pow(distance, 2));
        std::cout << key << ' ' << value << std::endl;
    }
}

} // namespace
