#include "Particle.h"
#include "Squash.h"
#include "Tools/Misc.hpp"

namespace Broptimiser
{


Particle::Particle(int size, double value)
:values(size, value)
{

}

Particle::Particle(int size, Tools::RNG& rng, bool restrict_to_positive)
:values(size)
{
    for(double& value: values)
    {
        value = unsquash(-500.0 + 1000.0*rng.rand());
        if(restrict_to_positive)
            value = std::abs(value);
    }
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

std::ostream& operator << (std::ostream& out, const Particle& particle)
{
    particle.print(out);
    return out;
}

} // namespace
