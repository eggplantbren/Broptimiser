#ifndef Broptimiser_Anything_h
#define Broptimiser_Anything_h

#include "Tools/RNG.hpp"

namespace Broptimiser
{

class Anything
{
    private:
        double coeff;
        double power;

    public:
        Anything(double _value=1.0);
        void perturb(Tools::RNG& rng);
        double value() const;
};

} // namespace

#endif
