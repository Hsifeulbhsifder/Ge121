#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void GetCoffeeData(ifstream& fin, int ratings[9][4]){
    int temp, grind, rating;
    while(fin >> temp >> grind >> rating){
        ratings[temp - 91][grind - 1] += rating;
    }
}

void PrintData(int ratings[9][4]){

    cout << "         1    2    3    4" << endl << endl;
    for(int i = 0; i < 9; i++){
        cout << i + 91 << setw(9);
        for(int j = 0; j < 4; j++){
            cout << ratings[i][j] << setw(5);
        }
        cout << setw(0) << endl;
    }
    cout << endl;
}

int SumRowOrColumn(int ratings[9][4], bool row,
                      int index){
    int sum = 0;
    if(row){
        for(int i = 0; i < 4; i++){
            sum += ratings[index][i];
        }
    } else {
        for(int i = 0; i < 9; i++){
            sum += ratings[i][index];
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

int main(){
    ifstream coffee1("coffee1.txt");
    ifstream coffee2("coffee2.txt");
    ifstream coffee3("coffee3.txt");

    int ratings[9][4] = {0};
    GetCoffeeData(coffee1, ratings);
    GetCoffeeData(coffee2, ratings);
    GetCoffeeData(coffee3, ratings);

    PrintData(ratings);

    int bestTempCoffee = 0, temp, grind;
    for(int i = 0; i < 9; i++){
        int sum = SumRowOrColumn(ratings, 1, i);
        if(sum > bestTempCoffee){
            bestTempCoffee = sum;
            temp = i + 91;
        }
    }

    cout << "The ideal temperature is " << temp << endl;
    RateTemperatureAndCoarseness(ratings, temp, grind);
    cout << "The ideal temperature and coarseness is " << temp 
         << " and " << grind << endl;

}