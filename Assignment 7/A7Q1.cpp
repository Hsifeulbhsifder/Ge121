//Zaeem Mohamed, Eugene Wang
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
	char answers[30];
	ifstream ansin("pascal2016.txt");
	if(ansin){
		int numQuestions = 0;
		while(ansin >> answers[numQuestions]){
			numQuestions++;
		}

		string school;
		int studentID, totalMarks = numQuestions * 5;
		ifstream responsin("answers2016.txt");
		ofstream marksout("results.txt");
		if(responsin){
			marksout << "School    IDs   Mark(%)" 
					 << endl << endl;
			while(responsin >> school >> studentID){
				int sum = 0, numBlank = 0;
				char currentAnswer;
				for(int i = 0; i < numQuestions; i++){
					responsin >> currentAnswer;
					if(currentAnswer == '0' && numBlank < 10){
						sum += 2;
						numBlank++;
					}else if(currentAnswer == answers[i]){
						sum += 5;
					}
				}
				double mark = 100.0 * sum / (double)totalMarks;
				marksout << setw(6) << school << setw(7) 
						 << studentID << setw(8) << fixed 
						 << setprecision(1) << mark << endl; 
			}
		}else{
			cout << "answers2016.txt is not found" << endl;
		}
		responsin.close();
		marksout.close();
	}else{
		cout << "pascal2016.txt is not found" << endl;
	}
	ansin.close();
}

/* Output:

School    IDs   Mark(%)

 SMCSS   6906    40.0
  SCSS   2584    22.4
   WCI    365    24.8
  JMSS   4652    32.8
  FFHS   4296    34.4
 SNWSS   8695    36.0
 SMCSS  23373    33.6
 SNWSS  30235    27.2
   AHS   5433    24.8
SMDCVI  31423    23.2
   WCI  28852    29.6
 SDCSS  14565    18.4
   AHS  28326    31.2
   WCI  28238    24.8
SMDCVI  32558    13.6
 SNWSS  27651    24.0
  SCSS  11501    40.0
  SCSS  18709    30.4
 SDCSS   5228    22.4
   WCI   9789    20.8
   WCI   9539    20.8
 SDCSS  31839    44.8
SMDCVI  11460    29.6
  JMSS   2841    20.0
   AHS    602    13.6
   AHS  17893    24.0
SMDCVI  27622    20.8
 SDCSS  25985    16.0
   AHS   1205    18.4
   WCI  22673    18.4


*/