// Zaeem Mohamed

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	const double radToDeg = 180.0 / M_PI;
	const double degToRad = 1.0 / radToDeg;
	double angleA = 0;
	double angleB = 0;
	double angleC = 0;
	double sideA = 0;
	double sideB = 0;
	double sideC = 0;
	double areaABC = 0;

	cout << "Enter two side lengths and the contained angle:";
	cin >> sideA;
	cin >> sideB;
	cin >> angleC;

	double sideA2 = sideA * sideA;
	double sideB2 = sideB * sideB;

	sideC = sqrt( sideA2 + sideB2 - 2 * sideA * sideB * cos(angleC * degToRad) );

	double sideC2 = sideC * sideC;

	cout << "Side Lengths (a, b, c): " << sideA << " " 
		 << sideB << " " << sideC << endl;

	angleA = acos( (sideA2 - sideC2 - sideB2) / (-2 * sideB * sideC) ) * radToDeg;
	angleB = acos( (sideB2 - sideA2 - sideC2) / (-2 * sideA * sideC) ) * radToDeg;

	cout << "Cos law angles (A, B, C): " << angleA << " " 
		 << angleB << " " << angleC << endl;

	double sinC_sideC = sin(angleC * degToRad) / sideC;

	angleA = asin(sideA * sinC_sideC) * radToDeg;
	angleB = asin(sideB * sinC_sideC) * radToDeg;

	cout << "Sin law angles (A, B, C): " << angleA << " " 
		 << angleB << " " << angleC << endl;

	double semiperimeter = (sideA + sideB + sideC) / 2.0;
	areaABC = sqrt( semiperimeter * (semiperimeter - sideA) * (semiperimeter - sideB) 
					* (semiperimeter - sideC) );

	cout << "Area: " << areaABC << endl;

	return 0;
}

/*
Console output for test case 1:
Enter two side lengths and the contained angle:30 3 15
Side Lengths (a, b, c): 30 3 27.1133
Cos law angles (A, B, C): 163.359 1.64103 15
Sin law angles (A, B, C): 16.641 1.64103 15
Area: 11.6469

Console output for test case 2:
Enter two side lengths and the contained angle:2 20 30
Side Lengths (a, b, c): 2 20 18.2953
Cos law angles (A, B, C): 3.13328 146.867 30
Sin law angles (A, B, C): 3.13328 33.1333 30
Area: 10

Console output for test case 3:
Enter two side lengths and the contained angle:3 4 90
Side Lengths (a, b, c): 3 4 5
Cos law angles (A, B, C): 36.8699 53.1301 90
Sin law angles (A, B, C): 36.8699 53.1301 90
Area: 6

*/