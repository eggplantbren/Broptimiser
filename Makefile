CXX = g++
FLAGS = -O3 -march=native -std=c++20 -Wall -Wextra -pedantic

default:
	$(CXX) $(FLAGS) -c Particle.cpp
	$(CXX) $(FLAGS) -c Squash.cpp
