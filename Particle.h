#ifndef Broptimiser_Particle_h
#define Broptimiser_Particle_h

#include "Tools/RNG.hpp"
#include <ostream>
#include <vector>

namespace Broptimiser
{

class Particle
{
    private:
        std::vector<double> values;

    public:

        // No default constructor
        Particle() = delete;

        // Initialise with number of parameters/length of vector,
        // and the given value (default 0.0)
        Particle(int size, double value=0.0);

        // Initialise with all values
        Particle(std::vector<double>&& _values);

        // Perturb one or more values
        void perturb(Tools::RNG& rng);

        // Print to output stream
        void print(std::ostream& out) const;

        // Getter
        const std::vector<double>& get_values() const;
};


// Print to output stream
std::ostream& operator << (std::ostream& out, const Particle& particle);

} // namespace

#endif
