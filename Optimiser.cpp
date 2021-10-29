#include "Optimiser.h"
#include <iostream>
#include <fstream>
#include "sqlite_modern_cpp/hdr/sqlite_modern_cpp.h"

namespace Broptimiser
{

Optimiser::Optimiser(Function&& _function, Particle&& _particle)
:function(_function)
,particle(_particle)
,all_time_high(particle, 0.0)
,memdb(":memory:")
{
    f = function(particle.get_values());
    std::get<1>(all_time_high) = f;

    memdb << "PRAGMA JOURNAL_MODE = OFF;";
    memdb << "PRAGMA SYNCHRONOUS = 0;";
    memdb << "CREATE TABLE points (\
id INTEGER NOT NULL PRIMARY KEY,\
f  REAL NOT NULL);";
    memdb << "CREATE INDEX idx ON points (f);";

    insert_point();
}

void Optimiser::insert_point()
{
    memdb << "INSERT INTO points (f) VALUES (?);" << f;
    q = evaluate_quality(f);
}

double Optimiser::evaluate_quality(double _f)
{
    int count;
    memdb << "SELECT COUNT(id) FROM points WHERE f >= ?;"
          << _f >> count;
    return -count/5.0;
}

void Optimiser::explore(Tools::RNG& rng, int steps)
{
    std::cout << "Exploring..." << std::flush;

//    static std::fstream fout("output.txt", std::ios::out);
    int accepted = 0;
    for(int i=0; i<steps; ++i)
    {
        auto proposal = particle;
        proposal.perturb(rng);
        double f_prop = function(proposal.get_values());
        double q_prop = evaluate_quality(f_prop);
        if(rng.rand() <= exp(q_prop - q))
        {
            particle = proposal;
            f = f_prop;
            q = q_prop;
            ++accepted;
        }

        if(f > std::get<1>(all_time_high))
            all_time_high = {particle, f};

//        fout << f << std::endl;
    }
    insert_point();
    std::cout << "done. ";
    std::cout << "Acceptance rate = " << accepted << '/' << steps << '.';
    std::cout << std::endl;
    std::cout << "All time high = " << std::get<1>(all_time_high) << '.';
    std::cout << std::endl;
}


std::vector<double> Optimiser::get_best_params() const
{
    return std::get<0>(all_time_high).get_values();
}


} // namespace
