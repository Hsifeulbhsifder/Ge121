#include <iostream>
#include <cmath>
using namespace std;

int IntToArray(long number, int array[10]){
    int size = 0;
    for(int i = 0, j = 1000000000; i < 10; i++, j /= 10){
        long digitPlace = number / j;
        if(size || digitPlace > 0){
            size++;
        }
        array[9-i] = digitPlace;
        number -= digitPlace * j;
    }
    return size;
}

bool IsPalindrome(int array[10], int size){
    if(size < 2){
        return true;
    }else{
        bool equalDigits = (array[0] == array[size-1]);
        for(int i = 0; i < size; i++){
            array[i] = array[i+1];
        }
        return IsPalindrome(array, size-2) && equalDigits;
    }
}

int main(){
    long number;
    int numberArray[10];
    while (cin >> number && number >= 0){
        int size = IntToArray(number, numberArray);
        cout << number << " is ";
        if(IsPalindrome(numberArray, size)){
            cout << "a palindrome." << endl;
        } else{
            cout << "not a palindrome." << endl;
        }
    }
}

/* Output

12321
12321 is a palindrome.
1234321
1234321 is a palindrome.
123454321
123454321 is a palindrome.
12345654321
12345654321 is not a palindrome.
1234554321
1234554321 is a palindrome.
12312
12312 is not a palindrome.
3241
3241 is not a palindrome.
2341342432
2341342432 is not a palindrome.
12122121
12122121 is a palindrome.
-1

*/