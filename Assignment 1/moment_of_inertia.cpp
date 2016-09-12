// Zaeem Mohamed

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double mass = 0;
	double radius1 = 0;
	double radius2 = 0;

	cout << "Enter the mass of the hollow sphere: ";
	cin >> mass;
	cout << "Enter the outer radius of the hollow sphere: ";
	cin >> radius2;
	cout << "Enter the inner radius of the hollow sphere: ";
	cin >> radius1;

	double momentOfInertia = (2.0 / 5.0) * mass 
						   * ( ( pow(radius2, 5) - pow(radius1, 5) )
						   	 / ( pow(radius2, 3) - pow(radius1, 3) ) );

	cout << "The moment of inertia is " << momentOfInertia << endl;
	return 0;
}

/*
Console output for test case 1:
Enter the mass of the hollow sphere: 100
Enter the outer radius of the hollow sphere: 25
Enter the inner radius of the hollow sphere: 12
The moment of inertia is 27392.4

Console output for test case 2:
Enter the mass of the hollow sphere: 2
Enter the outer radius of the hollow sphere: 0.67
Enter the inner radius of the hollow sphere: 0.23
The moment of inertia is 0.372476

*/