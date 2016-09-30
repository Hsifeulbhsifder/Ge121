// Zaeem Mohamed 20658740, Tim Zheng 20608800
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;
int main ()
{
	ifstream fin("worldTime.txt");
	if(!fin)
	{
		cout << "Unable to open file" << endl;
		return -1;
	}
	string city;
	int militaryTime = 0;
	
	while(fin >> city)
	{
		fin >> militaryTime;
		
		int hours24 = militaryTime / 100;
		int hours = hours24;
		int minutes = militaryTime % 100;
		
		cout << city << endl;

		if (hours24 > 12)
		{
			hours -= 12;
		}else if(hours24 == 0){
			hours = 12;
		}
		
		cout << hours << ":" << setprecision(0);
		if(minutes < 10){
			cout << '0';
		}
		cout << minutes ; 
		if(hours24 >= 12){
			cout << " pm" << endl;
		} else{
			cout << " am" << endl;
		}
		
		/*
		Since arc length is proportional to the angle, and that the clock is
		evenly separated into 60 parts, we can calculate the angle per minute
		and angle per hour
		*/
		double minuteY = 10 * cos(minutes * M_PI / 30);
		double minuteX = sqrt(100 - minuteY * minuteY);		
		
		double hourY = 6 * cos(hours * M_PI / 6.0 + minutes * M_PI / 360.0);
		double hourX = sqrt(36 - hourY * hourY);
		
		cout << "Hour hand (x,y): (" << fixed << setprecision(2) << hourX << " , " 
			 << hourY << ")" << endl;
		cout << "Minute hand (x,y): (" << minuteX << " , " 
			 << minuteY << ")" << endl
			 << endl; 
		
	}
	
	fin.close();
}

/* Output

Waterloo
12:00 pm
Hour hand (x,y): (0.00 , 6.00)
Minute hand (x,y): (0.00 , 10.00)

Newfoundland
1:30 pm
Hour hand (x,y): (4.24 , 4.24)
Minute hand (x,y): (0.00 , -10.00)

Vancouver
9:00 am
Hour hand (x,y): (6.00 , -0.00)
Minute hand (x,y): (0.00 , 10.00)

Casablanca
5:00 pm
Hour hand (x,y): (3.00 , -5.20)
Minute hand (x,y): (0.00 , 10.00)

Kathmandu
10:45 pm
Hour hand (x,y): (3.65 , 4.76)
Minute hand (x,y): (10.00 , -0.00)

Beijing
1:00 am
Hour hand (x,y): (3.00 , 5.20)
Minute hand (x,y): (0.00 , 10.00)

Hawaii
7:00 am
Hour hand (x,y): (3.00 , -5.20)
Minute hand (x,y): (0.00 , 10.00)

*/
