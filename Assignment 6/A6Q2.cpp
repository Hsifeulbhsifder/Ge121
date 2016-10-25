#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void position(int latDeg, int latMin, int longDeg, int longMin,
			  double &x, double &y){
	x = (longDeg + longMin / 60.0) * 111.0 
		* cos((latDeg + latMin / 60.0) * M_PI/180.0);
	y = (latDeg + latMin / 60.0) * 111.0;
}

double distance(double x1, double y1, double x2, double y2){
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double calcRescueTime(double troubleX, double troubleY, 
					  double helpX, double helpY, 
					  double speedKnots){
	if(!speedKnots) speedKnots = 1E-8;
	return distance(troubleX, troubleY, helpX, helpY) 
		   		 / (speedKnots * 1.8536);
}

int main(){
	ifstream fin("ships.txt");
	if(fin){
		double latDeg, latMin, longDeg, longMin, speedKnots;
		cout << "Enter the lattitude degrees and minutes and "
			 << "longitude degrees and minutes: ";
		cin >> latDeg >> latMin >> longDeg >> longMin;
		double troubleX = 0, troubleY = 0;
		position(latDeg, latMin, longDeg, longMin, troubleX, 
				 troubleY);
		double minTime = 99999999;
		string rescuer = "", currentShip = "";
		while(fin >> currentShip >> latDeg >> latMin 
				  >> longDeg >> longMin >> speedKnots){
			double helpX = 0, helpY = 0;
			position(latDeg, latMin, longDeg, longMin, helpX, 
					 helpY);

			double rescueTime = calcRescueTime(troubleX, 
								troubleY, helpX, helpY, 
								speedKnots);
			if(rescueTime < minTime){
				minTime = rescueTime;
				rescuer = currentShip;
			}
		}

		cout << rescuer << " || " << minTime << endl;

	}
}