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