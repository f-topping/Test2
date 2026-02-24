#include <fstream>
#include "system.h"

//constructor
System::System(std::size_t N, double displacement,double radius, double boxSize, int seed) {

        this->boxSize= boxSize;
        this->  dist = std::uniform_real_distribution<double>(0, 1);
        this->displacement=displacement;
        this->gen = std::mt19937(seed);
        
        std::size_t nSide = static_cast<std::size_t>(boxSize/ (2*radius));

        for (std::size_t i = 0; i < nSide && disks.size() < N; ++i) {
            for (std::size_t j = 0; j < nSide && disks.size() < N; ++j) {
                disks.push_back(Disk(i * 2*radius, j * 2*radius, radius));
            }
        }
    }   

//overlap method - tests to see if multiple disks overlap
bool System::overlap(std::size_t i){
    for (std::size_t j = 0; j < disks.size(); ++j) {
        if (i!=j && disks[i].distance(disks[j]) < (disks[i].radius + disks[j].radius) ) {
            return true;
        }
    }
    return false;
}

//step method
void System::step() {
    for (size_t i=0; i<disks.size(); ++i) 
    {
        int selected_disk = std::rand() % disks.size();
        double oldx = disks[selected_disk].x;
        double oldy = disks[selected_disk].y;
        double dx = uniform(-displacement, displacement);
        double dy = uniform(-displacement, displacement);
        this->disks[selected_disk].move(dx, dy);
        
        enforceBoundaries(disks[selected_disk]);

        if (overlap(selected_disk)){
            disks[selected_disk].x = oldx;
            disks[selected_disk].y = oldy;
        }
       
    }
}

//enforce boundaries method
void System::enforceBoundaries(Disk & disk) {
        if (disk.x < 0) disk.x = 0;
        if (disk.x > boxSize) disk.x = boxSize;
        if (disk.y < 0) disk.y = 0;
        if (disk.y > boxSize) disk.y = boxSize;
    }

//uniform method
double System::uniform(double min, double max){
	return (max-min)*this->uniformDist(gen)+min;
}

//save method
void System::save(const std::string &filename){
    // save state of disks to file
    std::ofstream outFile(filename);
    outFile<<disks.size()<<std::endl;
    outFile<<"Comment"<<std::endl;
    for (Disk& disk : disks) {
      outFile<<"A "<<disk.x<<" "<<disk.y<<" "<<disk.radius<<std::endl;

    }
    outFile.close();
    
}
