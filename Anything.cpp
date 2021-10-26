#include "Anything.h"
#include <cmath>
#include "Tools/Misc.hpp"

namespace Broptimiser
{

Anything::Anything(double _value)
:coeff(1.0)
,power(log10(_value))
{

}

void Anything::perturb(Tools::RNG& rng)
{
    coeff += rng.randh();
    Tools::wrap(coeff, -1.0, 1.0);
    power = log10(power);
    power = 0.5 + atan(0.2*power)/M_PI;
    power += rng.randh();
    Tools::wrap(power);
    power = 5.0*tan(M_PI*(power - 0.5));
    power = pow(10.0, power);
}

double Anything::value() const
{
    return coeff*pow(10.0, power);
}

} // namespace

#include <iostream>
using namespace Broptimiser;

int main()
{
    Anything a;
    Tools::RNG rng;
    for(int i=0; i<1000; ++i)
    {
        a.perturb(rng);
        std::cout << a.value() << std::endl;
    }

    return 0;
}
