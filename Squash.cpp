#include "Squash.h"
#include <cmath>

namespace Broptimiser
{

double squash(double x)
{
    if(x >= 0.0)
        return log(x + 1.0);
    else
        return -log(1.0 - x);
}


double unsquash(double s)
{
    if(s >= 0.0)
        return exp(s) - 1.0;
    else
        return 1.0 - exp(-s);
}


}
