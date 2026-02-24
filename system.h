#ifndef SYSTEM_H
#define SYSTEM_H

#include "disk.h"
#include <string>
#include <random>
#include <vector>

//system class
class System {
	private:
		//variables of a system
		double boxSize;
		std::uniform_real_distribution<double> dist;
		double displacement;
	public:
		//methods of a system
		System(std::size_t N, double displacement, double radius, double boxSize, int seed);
		bool overlap(std::size_t i);
		void step();
		void enforceBoundaries(Disk & disk);
		void save(const std::string &filename);
		
		std::vector<Disk> disks;

		std::mt19937 gen;
		std::uniform_real_distribution<double> uniformDist;
		double uniform(double min, double max);
};

#endif
