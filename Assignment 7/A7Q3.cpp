// Insert names
#include <cmath> 
#include <fstream> 
using namespace std; 

#include "ccc_win.h" 
#include "ccc_msw.cpp" 
#include "ccc_shap.cpp" 

int ccc_win_main() {
	// Insert program code here 
	cwin.coord(-1, 1, 1, -1);
	for(int i = 0; i < 51000; i++){
		double x = 0.00001 * i;
		Circle c(Point(0, 0), 0.5 - x);
		Line l1(Point(-0.5-x, -0.5-x), Point(-0.5-x, 0.5+x));
		Line l2(Point(-0.5-x, 0.5+x), Point(0.5+x, 0.5+x));
		Line l3(Point(0.5+x, 0.5+x), Point(0.5+x, -0.5-x));
		Line l4(Point(0.5+x, -0.5-x), Point(-0.5-x, -0.5-x));
		cwin << c << l1 << l2 << l3 << l4;
	}

	return 0;
}