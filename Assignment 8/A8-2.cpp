// Assignment 8: Question 2
// Author: Udeshaya Wadhwa

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <fstream>
using namespace std;

class Fraction {
private:
    int num, den;
public:
    // Constructors
    Fraction() {
        (*this).num = 1;
        (*this).den = 1;
    }

    Fraction(int numerator, int denominator) {
        if (denominator == 0) {
            cout << "UNDEFINED: Denominator = 0, denominator set to arbitrary number."
                  << endl;
            denominator = numerator + 1;
        }
        (*this).num = numerator * (abs(denominator) / denominator);
        (*this).den = abs(denominator);
    }

    // Accessors
    int getNumerator() const {
        return (*this).num;
    }
    int getDenominator() const {
        return (*this).den;
    }
    double approximation(int places) const {
        return round((double((*this).num) / (*this).den) * pow(10.0, places)) / pow(10.0, places);
    }
    bool isExactlySame(Fraction const & other) const {
        return (other.getNumerator() == (*this).num) && (other.getDenominator() == (*this).den);
    }
    void output() const {
        cout << (*this).num << "/" << (*this).den << endl;
    }

    // Mutators
    void setNumerator(int numerator) {
        (*this).num = numerator;
    }
    void setDenominator(int denominator) {
        if (denominator == 0) {
            cout << "UNDEFINED: Denominator = 0, denominator set to arbitrary number."
                  << endl;
            denominator = (*this).num + 1;
        }
        (*this).num = (*this).num * (abs(denominator) / denominator);
        (*this).den = abs(denominator);
    }

};

int main() {

    // Default Constructor & Output Test
    Fraction f0;
    cout << "f0 (default constructor): "; f0.output();

    // Positive Numerator & Positive Denominator
    Fraction f1(4, 7);
    cout << "f1: "; f1.output();

    // Negative Numerator & Positive Denominator
    Fraction f2(-4, 7);
    cout << "f2: "; f2.output();

    // Positive Numerator & Negative Denominator
    Fraction f3(4, -7);
    cout << "f3: "; f3.output();

    // Negative Numerator & Negative Denominator
    Fraction f4(-4, -7);
    cout << "f4: "; f4.output();

    // Access Numerator & Access Denominator
    cout << "f2 Numerator: " << f2.getNumerator()
          << ", f2 Denominator: " << f2.getDenominator() << endl;

    // Access Approximation of Fraction
    cout << "f3 Approximation to 4 decimal places: " << f3.approximation(4) << endl;
    cout << "f3 Approximation to 7 decimal places: " << f3.approximation(7) << endl;

    // Access isExactlySame Function
    cout << "f2 & f3 isExactlySame() results in: " << f2.isExactlySame(f3) << endl;
    cout << "f2 & f4 isExactlySame() results in: " << f2.isExactlySame(f4) << endl;

    // Mutate Numerator
    f0.setNumerator(5);
    cout << "f0 with modified numerator: "; f0.output();

    // Mutate Denominator
    f0.setDenominator(6);
    cout << "f0 with modified denominator: "; f0.output();

    // Denominator Zero Case
    Fraction f5(3, 0);
    cout << "f5: "; f5.output();

    return EXIT_SUCCESS;
}

/* Output:
f0 (default constructor): 1/1
f1: 4/7
f2: -4/7
f3: -4/7
f4: 4/7
f2 Numerator: -4, f2 Denominator: 7
f3 Approximation to 4 decimal places: -0.5714
f3 Approximation to 7 decimal places: -0.571429
f2 & f3 isExactlySame() results in: 1
f2 & f4 isExactlySame() results in: 0
f0 with modified numerator: 5/1
f0 with modified denominator: 5/6
UNDEFINED: Denominator = 0, denominator set to arbitrary number.
f5: 3/4
*/
