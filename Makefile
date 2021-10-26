CXX = g++
FLAGS = -O3 -march=native -std=c++20 -Wall -Wextra -pedantic

default:
	$(CXX) $(FLAGS) -c Particle.cpp
	$(CXX) $(FLAGS) -c Squash.cpp
	ar rcs libBroptimiser.a *.o
	$(CXX) $(FLAGS) -c main.cpp
	$(CXX) -L . -o main main.o -lBroptimiser
	rm *.o
