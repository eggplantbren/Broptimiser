#ifndef Broptimiser_Optimiser_h
#define Broptimiser_Optimiser_h

#include "Particle.h"
#include <functional>
#include <set>

namespace Broptimiser
{

using Function = std::function<double(const std::vector<double>&)>;

class Optimiser
{
    private:

        Function function;
        Particle particle;
        Particle best;
        std::multiset<double> function_evaluations;

    public:
        Optimiser() = delete;

        // You have to pass sensible initial conditions
        Optimiser(Function&& _function, Particle&& _particle);
};

} // namespace

#endif
