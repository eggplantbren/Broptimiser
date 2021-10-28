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
        double f, q;
        std::tuple<Particle, double> all_time_high;
        sqlite::database memdb;
        double evaluate_quality(double _f);
        void insert_point();

    public:
        Optimiser() = delete;

        // You have to pass sensible initial conditions
        Optimiser(Function&& _function, Particle&& _particle);

        // Explore for a while
        void explore(Tools::RNG& rng, int steps=1000);
};

} // namespace

#endif
