CXX = g++
FLAGS = -std=c++20 -O3 -march=native -Wall -Wextra -pedantic

default:
	$(CXX) $(FLAGS) -c Optimiser.cpp
	$(CXX) $(FLAGS) -c Particle.cpp
	$(CXX) $(FLAGS) -c Squash.cpp
	ar rcs libBroptimiser.a *.o
	$(CXX) $(FLAGS) -c main.cpp
	$(CXX) -L . -o main main.o -lBroptimiser
	rm *.o
