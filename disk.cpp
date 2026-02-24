#include "disk.h"
#include <cmath>

//Disk constructor.
Disk::Disk(double x, double y, double r){
    this->x = x;
    this->y = y;
    this->radius = r;
}

//Disk move function, takes double amounts of directional movement.
void Disk::move(double dx, double dy){
    this->x += dx;
    this->y += dy;
}

//Finds and returns the distance between two disks (double).
double Disk::distance(Disk& other){
	double x_difference = this->x - other.x;
	double y_difference = this->y - other.y;
	return std::sqrt(x_difference * x_difference + y_difference * y_difference);
    // HINT: COMPLETE THE CALCULATION OF THE DISTANCE BETWEEN this DISK AND THE DISK other

}
