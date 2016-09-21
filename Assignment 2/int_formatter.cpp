// Zaeem Mohamed, Udeshaya Wadhwa

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){

	int integer = 0;
	const int fileSize = 10;

	ifstream fin("int_formatter.txt");

	if(fin.is_open()){
		for(int i = 0; i < fileSize; i++){
			fin >> integer;

			cout << "Input: " << integer;

			if(integer > 1000 && integer < 1000000){
				int highWord = integer / 1000;
				int lowWord = integer - highWord * 1000;
				cout << " | Output: " << highWord << "," << lowWord << endl;
			}else{
				cout << " | Number is not in the thousands" << endl;
			}
		}

	}else{
		cout << "int_formatter.txt not found" << endl;
	}

	return 0;
}

/*

Output:

Input: 124321 | Output: 124,321
Input: 999 | Number is not in the thousands
Input: 1243216 | Number is not in the thousands
Input: 74829 | Output: 74,829
Input: 9463 | Output: 9,463
Input: 1954783 | Number is not in the thousands
Input: 134 | Number is not in the thousands
Input: 184392 | Output: 184,392
Input: 12452 | Output: 12,452
Input: 7535 | Output: 7,535

*/