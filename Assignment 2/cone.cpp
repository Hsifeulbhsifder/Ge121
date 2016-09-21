// Zaeem Mohamed, Udeshaya Wadhwa

#include <iostream>
#include <cmath>

using namespace std;

int main(){

	double radius = 0, angle = 0;


	cout << "Enter angle in degrees and radius: ";

	cin >> angle >> radius;

	if(angle > 0.0 && angle < 360.0){
		double coneRadius = (angle / 360.0) * radius;
		double coneHeight = sqrt(radius * radius 
							- coneRadius * coneRadius);
		double volume = (1.0 / 3.0) * M_PI * coneRadius 
						* coneRadius * coneHeight;
		cout << "Volume: " << volume << endl;
	} else {
		cout << "Angle is not between 0 and 360 degrees" 
			 << endl;
	}

	return 0;
}

/*

Output for test case 1:

Enter angle in degrees and radius: 90 1
Volume: 0.0633715

Output for test case 2:

Enter angle in degrees and radius: -2 23
Angle is not between 0 and 360 degrees

Output for test case 3:

Enter angle in degrees and radius: 15.4 15.4
Volume: 6.99245

Output for test case 4:

Enter angle in degrees and radius: 365 15
Angle is not between 0 and 360 degrees

Output for test case 5:

Enter angle in degrees and radius: 160 2000
Volume: 1.48241e+009

Output for test case 6:

Enter angle in degrees and radius: 0.54 1000
Volume: 2356.19

*/