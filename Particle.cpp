#include "Particle.h"
#include "Squash.h"

namespace Broptimiser
{


Particle::Particle(int size, double value)
:values(size, value)
{

}

Particle(int size, Tools::RNG& rng, bool restrict_to_positive)
:values(size)
{
    for(double& value: values)
    {
        value = unsquash(-1000.0 + 2000.0*rng.rand());
        if(restrict_to_positive)
            value = std::abs(value);
    }
}

} // namespace
