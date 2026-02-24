#ifndef DISK_H
#define DISK_H

//disk header file: disk class
class Disk{
	private:
		//coordinates and radius
		double x;
		double y;
		double radius;
	public:
		//constructor, move and distance calculation functions
		Disk(double x, double y, double r);
		void move(double dx, double dy);
		double distance(Disk& other);
};

#endif
		
