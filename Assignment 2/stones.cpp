// Zaeem Mohamed, Udeshaya Wadhwa

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
	const double LEN_TOL = 0.1;
	const double ANGLE_TOL = 0.5;
	double side1 = 0, side2 = 0, angle = 0;

	const int fileSize = 6;
	ifstream fin("stones.txt");

	if(!fin.is_open()){

		cout << "stones.txt not found" << endl;
		return -1;

	}

	for(int i = 0; i < fileSize; i++){

		fin >> side1 >> side2 >> angle;
		cout << "Sides: " << side1 << "cm " 
		<< side2 << "cm | Angle: ";

		if(angle > -ANGLE_TOL && angle < (180.0 + ANGLE_TOL)){

			cout << angle << " degrees | Shape: ";

			if(fabs(angle - 90.0) < ANGLE_TOL){

				if(fabs(side2 - side1) < LEN_TOL){

					cout << "Square" << endl;

				}else{

					cout << "Rectangle" << endl;

				}

			}else{

				if(fabs(side2 - side1) < LEN_TOL){

					cout << "Rhombus" << endl;

				}else{

					cout << "Parallelogram" << endl;

				}

			}

		}else {

			cout << "does not fit the interval [0,180] degrees." 
			<< endl;

		}

	}

	fin.close();

	return 0;
}

/*

Output:

Sides: 10cm 10.05cm | Angle: 90.4 degrees | Shape: Square
Sides: 10cm 10.15cm | Angle: 89.6 degrees | Shape: Rectangle
Sides: 10cm 10.05cm | Angle: does not fit the interval [0,180] degrees.
Sides: 20cm 20.05cm | Angle: 30 degrees | Shape: Rhombus
Sides: 20cm 15cm | Angle: 120 degrees | Shape: Parallelogram
Sides: 10cm 15.05cm | Angle: does not fit the interval [0,180] degrees.

*/