// Assignment 8: Question 1
// Authors: Udeshaya Wadhwa & Zaeem Mohamed
// Best coffee is determined through highest total rating by Chris.
// Udeshaya is A, Zaeem is B
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <fstream>
using namespace std;

void updateArray(ifstream & in, int arr[9][4]) {
    int temp, type, rating;
    while (in >> temp >> type >> rating) {
        arr[temp - 91][type - 1] += rating;
    }
}

void PrintData(int ratings[9][4]){

    cout << "   Coarseness    1    2    3    4" << endl 
         << "Temperature" << endl;
    for(int i = 0; i < 9; i++){
        cout << i + 91 << setw(17);
        for(int j = 0; j < 4; j++){
            cout << ratings[i][j] << setw(5);
        }
        cout << setw(0) << endl;
    }
    cout << endl;
}

int sumValues(int arr[9][4], bool row_or_col, int index) {
    // True: Row | False: Column
    int sum = 0;
    if (row_or_col) {
        for (int j = 0; j < 4; j++) {
            sum += arr[index][j];
        }
    } else {
        for (int i = 0; i < 9; i++) {
            sum += arr[i][index];
        }
    }
    return sum;
}

void RateTemperatureAndCoarseness(int ratings[9][4], 
                                  int& temp, int& grind){
    int bestRating = 0;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 4; j++){
            if(ratings[i][j] > bestRating){
                bestRating = ratings[i][j];
                temp = 91 + i;
                grind = 1 + j;
            }
        }
    }

}

int main() {

    int idealCoarse, idealTemp, bestTemp;

    ifstream fin1("coffee1.txt");
    ifstream fin2("coffee2.txt");
    ifstream fin3("coffee3.txt");

    if (!fin1 || !fin2 || !fin3) {
        cout << "ERROR: Files unable to load!";
        return EXIT_FAILURE;
    }

    int dataArr[9][4] = {0};
    updateArray(fin1, dataArr);
    updateArray(fin2, dataArr);
    updateArray(fin3, dataArr);

    PrintData(dataArr);
    RateTemperatureAndCoarseness(dataArr, 
                idealCoarse, idealTemp);

    int maxScore = sumValues(dataArr, true, 0);
    for (int i = 1; i < 9; i++) {
        if (sumValues(dataArr, true, i) > maxScore) {
            maxScore = sumValues(dataArr, true, i);
            bestTemp = i + 91;
        }
    }

    cout << endl << "Best temperature for brewing is " 
         << bestTemp << "." << endl;
    cout << "Ideal combination for coffee is at a temperature of "
         << idealTemp << " and a coarseness of " 
         << idealCoarse << "." << endl;

    fin1.close();
    fin2.close();
    fin3.close();
    return EXIT_SUCCESS;
}

/* Output:
   Coarseness    1    2    3    4
Temperature
91               10   21   12   18
92               17    7   18   11
93               17   27   19   17
94               13   12   11   15
95               13   15   19   21
96               15   14   14   15
97               15   28   12   18
98               16   16   16   19
99               25   14   12   18


Best temperature for brewing is 93.
Ideal combination for coffee is at a temperature of 2 and a coarseness of 97.
*/
