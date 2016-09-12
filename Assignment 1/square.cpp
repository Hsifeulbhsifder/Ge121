// Zaeem Mohamed

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    ofstream fout("square.txt");

    int a = 0;
    cout << "Enter a number: ";
    cin >> a;

    cout << "The square of " << a << " is " << a * a << endl;
    fout << "The square of " << a << " is " << a * a << endl;

    cout << a << " cubed is " << a * a * a << endl;

    fout.close();
    return 0;
}

/*
Console output:
Enter a number: 9
The square of 9 is 81
9 cubed is 729

File output:
The square of 9 is 81

*/
