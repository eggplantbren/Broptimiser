#include "Optimiser.h"
#include <iostream>
#include "sqlite_modern_cpp/hdr/sqlite_modern_cpp.h"

namespace Broptimiser
{

Optimiser::Optimiser(Function&& _function, Particle&& _particle)
:function(_function)
,particle(_particle)
,all_time_high(particle, 0.0)
,memdb(":memory:")
{
    std::get<1>(all_time_high) = function(particle.get_values());

    memdb << "PRAGMA JOURNAL_MODE = OFF;";
    memdb << "PRAGMA SYNCHRONOUS = 0;";
    memdb << "CREATE TABLE points (\
id INTEGER NOT NULL PRIMARY KEY,\
f  REAL NOT NULL);";
    memdb << "CREATE INDEX idx ON points (f);";
}


} // namespace
