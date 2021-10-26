#include "Particle.h"
#include "Tools/Misc.hpp"

namespace Broptimiser
{


Particle::Particle(int size, double value)
:values(size, value)
{

}

Particle::Particle(std::vector<double>&& _values)
{
    for(size_t i=0; i<_values.size(); ++i)
        values.emplace_back(_values[i]);
}

void Particle::perturb(Tools::RNG& rng)
{
    int reps = 1;
    if(rng.rand() <= 0.5)
        reps = int(pow(values.size(), rng.rand()));

    int k;
    for(int rep=0; rep<reps; ++rep)
    {
        k = rng.rand_int(values.size());
        values[k].perturb(rng);
    }
}

// Print to output stream
void Particle::print(std::ostream& out) const
{
    auto xs = get_values();
    for(size_t i=0; i<xs.size(); ++i)
    {
        out << xs[i];
        if(i != xs.size() - 1)
            out << ',';
    }
}

std::vector<double> Particle::get_values() const
{
    std::vector<double> result(values.size());
    for(size_t i=0; i<values.size(); ++i)
        result[i] = values[i].value();
    return result;
}


std::ostream& operator << (std::ostream& out, const Particle& particle)
{
    particle.print(out);
    return out;
}

} // namespace
