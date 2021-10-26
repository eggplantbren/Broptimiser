#include "Particle.h"
#include "Squash.h"
#include "Tools/Misc.hpp"

namespace Broptimiser
{


Particle::Particle(int size, double value)
:values(size, value)
{

}

Particle::Particle(std::vector<double>&& _values)
:values(_values)
{

}

void Particle::perturb(Tools::RNG& rng)
{
    int reps = 1;
    if(rng.rand() <= 0.5)
        reps = int(pow(values.size(), rng.rand()));

    int k;
    double s;
    for(int rep=0; rep<reps; ++rep)
    {
        k = rng.rand_int(values.size());
        s = squash(values[k]);
        s += 1000.0*rng.randh();
        Tools::wrap(s, -500.0, 500.0);
        values[k] = unsquash(s);
    }
}

// Print to output stream
void Particle::print(std::ostream& out) const
{
    for(size_t i=0; i<values.size(); ++i)
    {
        out << values[i];
        if(i != values.size() - 1)
            out << ',';
    }
}

const std::vector<double>& Particle::get_values() const
{
    return values;
}


std::ostream& operator << (std::ostream& out, const Particle& particle)
{
    particle.print(out);
    return out;
}

} // namespace
