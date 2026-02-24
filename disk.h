#ifndef DISK_H
#define DISK_H

//disk header file: disk class
class Disk{
	public:
		//coordinated and radius
		double radius;
		double y;
		double x;

		//constructor, move and distance calculation functions
		Disk(double x, double y, double r);
		void move(double dx, double dy);
		double distance(Disk& other);
};

#endif
		
