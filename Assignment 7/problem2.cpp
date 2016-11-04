//Eugene Wang, Zaeem Mohamed
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string.h>
#include <fstream>
 
using namespace std;


const int resistorScope = 11;
const int neededResistor = 275;
int resisters[resistorScope] = {275};


int main (){	
	ifstream fin ("resist.txt");
	ofstream fout ("report.txt"); 
	if(!fin.is_open())
	{
		cout <<"oops";
		return 1;
	}
	
	
	int resistorIndex = 0;
	while (fin >> resistorIndex)
	{
		resisters[resistorIndex/100]++; 
	}
	
	fout <<"These resistors need to be purchased: "<<endl;
	
	for (int i = 0; i < resistorScope; i++)
	{
		int purchase = 0;
		if ((purchase =  neededResistor - resisters[i]) > 0)
		{
			fout << "Resistor " << i*100 <<": "<<purchase <<endl;
		}
	}
	return 0;
}
/* Output:

These resistors need to be purchased: 
Resistor 300: 2
Resistor 400: 39
Resistor 800: 17

*/ 

