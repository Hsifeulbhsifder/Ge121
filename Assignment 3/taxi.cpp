// Zaeem Mohamed 20658740, Tim Zheng 20608800
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

int main(){

	ifstream fin("taxi.txt");
	if(!fin){
		cout << "Unable to open file" << endl;
		return -1;
	}

	bool returnTrip = 0;
	double totalDist = 0;
	double totalCost = 0;
	int tripNum = 0;

	while (fin >> returnTrip){
		tripNum++;
		int stops = 0;
		double x = 0;
		double y = 0;
		double xPos = 0;
		double yPos = 0;
		double distance = 0;
		double cost = 0;
	}


}