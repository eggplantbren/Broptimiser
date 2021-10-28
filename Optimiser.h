#ifndef Broptimiser_Optimiser_h
#define Broptimiser_Optimiser_h

#include "Particle.h"
#include <functional>
#include <map>
#include "sqlite_modern_cpp/hdr/sqlite_modern_cpp.h"
#include <tuple>

namespace Broptimiser
{

using Function = std::function<double(const std::vector<double>&)>;

class Optimiser
{
    private:

        Function function;
        Particle particle;
        std::tuple<Particle, double> all_time_high;
        sqlite::database memdb;

    public:
        Optimiser() = delete;

        // You have to pass sensible initial conditions
        Optimiser(Function&& _function, Particle&& _particle);
};

} // namespace

#endif
