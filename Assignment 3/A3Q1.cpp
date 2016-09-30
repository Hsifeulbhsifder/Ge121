// Zaeem Mohamed 20658740, Tim Zheng 20608800
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;
int main () {
	int digits = 0;
	do {
		cout << "Enter number of digits (2-5): ";
		cin >> digits;
	} while (digits < 2 || digits > 5);
	
	int start = int(pow(10.0, digits - 1));
	
	double minDifference = 999999999;
	int numerator = 0;
	int denominator = 0;
	int iterations = 0;
	
	for (int i = (start * 10 - 1) / 3 - start / 10.0; i >= start; i--){
		for (int j = i * 2.72; j >= (2.718 * i); j--){
			if (fabs((double)j / (double)i - M_E) < minDifference) {
				minDifference = fabs((double)j / (double)i - M_E);
				numerator = j;
				denominator = i;

			}	
			iterations++;
		}	
	}
	
	cout << "Best Approximation is: " << numerator << "/" << denominator 
		 << endl;
	cout << (double) numerator / (double) denominator << " " 
		 << minDifference * 100.0 / M_E << endl;
	cout << "# of iterations: " << iterations << endl;
	
}

/*
Output cases:

Enter number of digits (2-5): 2
Best Approximation is: 87/32
2.71875 0.0172231
# of iterations: 2

Enter number of digits (2-5): 3
Best Approximation is: 878/323
2.71827 0.000572957
# of iterations: 99

Enter number of digits (2-5): 4
Best Approximation is: 8163/3003
2.71828 4.0532e-006
# of iterations: 9503

Enter number of digits (2-5): 5
Best Approximation is: 49171/18089
2.71828 1.01774e-008
# of iterations: 945933


There are a some optimizations going on here:

1) Reversely iterating through the denominators starting at:
   (10^n - 1) / 3 - 10^(n-2) and going down to: 10^(n-1).
   This is done because we know that e is less than 3, so if
   the numerator was the highest possible value for the number 
   of digits n, the denominator would be less than or equal to
   (10^n - 1) / 3 - 10^(n-2) and would stop at the lowest
   possible value for n digits.

2) Reversely iterating through the numerators starting at:
   denominator * 2.8 and going down to: denominator * 2.718.
   This is done because we know the fraction must belong
   either slightly above or below e. This way, we guarantee
   that only fractions around e are checked.

*/
