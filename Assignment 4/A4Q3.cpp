//Zaeem Mohamed, Charvi Shah

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double convDeg(int deg, int mins){
	return (double)(deg + mins/60.0);
}

double findX(double lat, double lon){
	return lon * (111.0 * cos(lat * M_PI / 180.0));
}

double findY(double lat){
	return lat * 111.0;
}

int main(){
	ifstream fin("message.txt");
	if(fin){
		int lat, latMins, lon, lonMins, deliveries;
		fin >> lat >> latMins >> lon >> lonMins >> deliveries;
		double srcX = findX(convDeg(lat, latMins), 
					  convDeg(lon, lonMins));
		double srcY = findY(convDeg(lat, latMins));

		while(deliveries--){
			double destLat, destLatMins, destLon, destLonMins;
			fin >> destLat >> destLatMins 
				>> destLon >> destLonMins;
			double deltaX = findX(convDeg(destLat, destLatMins), 
					  	   convDeg(destLon, destLonMins)) - srcX;
			double deltaY = findY(convDeg(destLat, destLatMins)) 
						  - srcY;

			cout << "Distance: " << sqrt(deltaX * deltaX 
				 + deltaY * deltaY) << " | Angle: " 
				 << 180.0 / M_PI * atan2(deltaY, deltaX) << endl;
		}
	}

	fin.close();
	return 0;
}

/*	
	Assumption: An angle of 0 means that
				the direction is due East

	Output:
	Distance: 1286.55 | Angle: 75.7378
	Distance: 11.5241 | Angle: 9.2378
	Distance: 913.522 | Angle: -56.7596
	Distance: 472.81 | Angle: -105.732
	Distance: 1387.5 | Angle: 112.879
	Distance: 324.497 | Angle: -22.4561
	Distance: 1006.12 | Angle: 128.266
	Distance: 1590.1 | Angle: -0.733289
*/