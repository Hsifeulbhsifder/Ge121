//Zaeem Mohamed, Felix Wu
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

double areaTri(double a, double b, double c){
	double semiPerim = (a + b + c) / 2.0;
	return sqrt(semiPerim * (semiPerim - a) 
		   * (semiPerim - b) * (semiPerim - c));
}

double perimTri(double a, double b, double c){
	return a + b + c;
}

double areaQuad(double a, double b, double diag, 
				double c, double d){
	return areaTri(a, b, diag) + areaTri(b, c, diag);
}

double perimQuad(double a, double b, double c, double d){
	return a + b + c + d;
}

double areaSector(double radius, double angle){
	return M_Pi * radius * radius * angle / 360.0;
}

double perimSector(double radius, double angle){
	return 2 * radius * (1 + M_Pi * angle / 360.0);
}

void calculateAndPrintCosts(int jobNum, bool isFenced,
							double area, double perimeter){
	double pavingCost = ceil(area) * 18.5;
	double fencingCost = ceil(perimeter) * 26.0 + 120.0;
	if(isFenced){
		perimeter = 0;
		fencingCost = 0;
	}
	double subTotal = pavingCost + fencingCost + 35.0;
	double taxes = subTotal * 0.13;
	cout << jobNum << "||" << area << "||" << pavingCost 
		 << "||" << perimeter << "||" << fencingCost 
		 << "||" << taxes << "||" << taxes + subTotal << endl;

}

int main(){
	
}