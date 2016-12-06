#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

class Racecar{
public:
	string name;
	int number;
	string make;
private:
	double maxVel;
	double maxAcc;

public:

	Racecar(){
		name = "Paul Walker";
		number = -1;
		make = "Totalled";
		maxVel = -1;
		maxAcc = -1;
	}

	Racecar(string name, int number, string make, int maxVel,
			int maxAcc){
		this->name = name;
		this->number = number;
		this->make = make;
		this->maxVel = maxVel;
		this->maxAcc = maxAcc;
	}

	bool InitFromFile(ifstream& fin){
		if(fin){
			fin >> name >> number >> make >> maxVel >> maxAcc;
			return true;
		}
		return false;
	}

	double GetMaxVel() const{
		return maxVel;
	}

	double GetMaxAcc() const{
		return maxAcc;
	}

	void SetMaxVel(double newMaxVel){
		maxVel = newMaxVel;
	}

	void SetMaxAcc(double newMaxAcc){
		maxAcc = newMaxAcc;
	}

	void CopyGearing(Racecar const& racecar){
		maxVel = racecar.maxVel;
		maxAcc = racecar.maxAcc;
	}

	double CalculateDistance(double initVel, double time) const{
		if(initVel > maxVel){
			initVel = maxVel;
		}

		double timeToMax = (maxVel - initVel) / maxAcc;
		double distance = 0;
		if(timeToMax < time){
			distance = (time - timeToMax) * maxVel;
		}
		
		distance += timeToMax * (initVel + 0.5 
				 * maxAcc * timeToMax);

		return distance;		
	}

	double CalculateTime(double initVel, double distance) const{
		if(initVel > maxVel){
			initVel = maxVel;
		}

		double distanceToMax = (maxVel * maxVel - initVel 
							 * initVel) * 0.5 / maxAcc;
		if(distanceToMax >= distance){
			double finVel = sqrt((initVel * initVel) 
						  + (2 * maxAcc * distance));
			return (finVel - initVel) / maxAcc;
		}else{
			return (maxVel - initVel) / maxAcc 
				 + (distance / maxVel);
		}
	}

};


int main(){
	ifstream fin("racecars.txt");

	if(fin){
		Racecar cars[4];
		double times[4];
		for(int i = 0; i < 4; i++){
			if(!cars[i].InitFromFile(fin)){
				cout << "Failure" << endl;
				return -1;
			}

			times[i] = cars[i].CalculateTime(0, 402);
		}

		int winner1, winner2, winner3;
		if(times[0] < times[1]){
			winner1 = 0;
		}else {
			winner1 = 1;
		}

		if(times[2] < times[3]){
			winner2 = 2;
		}else {
			winner2 = 3;
		}

		if(times[winner1] < times[winner2]){
			winner3 = winner1;
		}else {
			winner3 = winner2;
		}
		cout << cars[0].name << endl;
		cout << "\t\t\t" << cars[winner1].name << endl;
		cout << cars[1].name << endl;
		cout << "\t\t\t\t\t\t\t" << cars[winner3].name << endl;
		cout << cars[2].name << endl;
		cout << "\t\t\t" << cars[winner2].name << endl;
		cout << cars[3].name << endl;

	}
}

/* Output:

TheSnake
			Herbie
Herbie
							Herbie
Mongoose
			SpeedRacer
SpeedRacer

*/