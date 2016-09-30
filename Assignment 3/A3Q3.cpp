// Zaeem Mohamed 20658740, Tim Zheng 20608800
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;
int main(){
	ofstream fout("taxi_output.txt");
	ifstream fin("taxi.txt");
	if(!fin){
		cout << "Unable to open file" << endl;
		return -1;
	}
	
	bool returnTrip = 0;
	double totalDist = 0;
	double totalCost = 0;
	int tripNum = 0;
	
	fout << "Trip #" << setw(8) << "Return" << setw(7) 
		 << "# Stop" << setw(8) << "Dist" << setw(8) 
		 << "Cost" << setw(14) << "Total Dist" << setw(14) 
		 << "Total Cost" << endl;
	
	while (fin >> returnTrip){
		tripNum++;
		int stops = 0;
		double x = 0;
		double y = 0;
		double xPos = 0;
		double yPos = 0;
		double dist = 0;		
		double cost = 0;

		fin >> stops;
		for (int i = 0; i < stops; i++){
			fin >> x >> y;
			xPos += x;
			yPos += y;
			dist += sqrt(x * x + y * y);
		}

		if (returnTrip){
			dist += sqrt(xPos * xPos + yPos * yPos);	
		}
		totalDist += dist;
		
		cost = (15 * stops) + (2.1 * dist);
		totalCost += cost;	
		
		if(tripNum < 5 || tripNum % 10 == 4){
			fout << fixed << setprecision(2) << setw(2) << tripNum 
				 << setw(8) << returnTrip << setw(8) 
				 << stops << setw(12) << dist << setw(8) << cost << setw(10)
				 << setw(12) << totalDist << setw(12) << totalCost << endl;
		}

	}
	fout << endl << "Total distance driven in August: " << totalDist << endl;
	fout << "Total money collected in August: " << totalCost << endl;
	fin.close();
}

/* Output:

Trip #  Return # Stop    Dist    Cost    Total Dist    Total Cost
 1       0       1       10.20   36.42       10.20       36.42
 2       1       2       15.21   61.94       25.41       98.36
 3       0       4       23.81  110.01       49.22      208.37
 4       0       3       17.35   81.44       66.58      289.81
14       0       4       27.75  118.28      385.63     1529.81
24       1       2       26.97   86.64      677.44     2652.61
34       0       3       18.40   83.64      967.13     3740.97
44       0       2       12.49   56.24     1180.04     4548.09
54       0       5       30.47  138.99     1496.33     5662.29
64       0       2       15.30   62.13     1757.51     6630.78
74       1       2       15.68   62.92     1969.31     7435.56

Total distance driven in August: 2055.87
Total money collected in August: 7752.34

*/