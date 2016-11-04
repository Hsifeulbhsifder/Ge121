//Zaeem Mohamed
#include <cmath> 
#include <fstream> 
using namespace std; 

#include "ccc_win.h" 

int ccc_win_main() {
	// Insert program code here 
	cwin.coord(-1, 1, 1, -1);
	int numDrawings = cwin.get_int("How many drawings do you want?");
	double radius = 0.1;
	double radiusRate = 0.05 / (numDrawings - 1);
	for(int j = 0; j < numDrawings; j++){
		Point p = cwin.get_mouse("Click");
		double px = p.get_x();
		double py = p.get_y();
		cwin << p;
		for(int i = 0; i < 5100; i++){
			double x = 0.0002 * i * radius;
			Circle c(p, radius - x);
			Line l1(Point(px-radius, py-radius), Point(px-radius-2*x, py+radius+2*x));
			Line l2(Point(px-radius, py+radius), Point(px+radius+2*x, py+radius+2*x));
			Line l3(Point(px+radius, py+radius), Point(px+radius+2*x, py-radius-2*x));
			Line l4(Point(px+radius, py-radius), Point(px-radius-2*x, py-radius-2*x));
			cwin << c << l1 << l2 << l3 << l4;
		}
		radius -= radiusRate;
	}

	return 0;
}