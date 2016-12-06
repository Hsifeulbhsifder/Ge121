#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

void LoadDepths(ifstream& fin, double depths[82][78]){
	for(int i = 0; i < 82; i++){
		for(int j = 0; j < 78; j++){
			fin >> depths[i][j];
		}
	}
}

void DrawLake(double depths[82][78], double boundary){
	for(int i = 0; i < 82; i++){
		for(int j = 0; j < 78; j++){
			int arrayLocation = (j + i * 82);
			if(depths[i][j] > boundary){
				char land;
				int location = arrayLocation % 2;
				if(location == 0){
					land = ' ';
				} else {
					land = '.';
				}
				cout << land;
			} else{
				char water;
				int location = arrayLocation % 11;
				if(location == 0){
					water = 'W';
				} else if(location == 1){
					water = 'A';
				} else if(location == 2){
					water = 'T';
				} else if(location == 3){
					water = 'E';
				} else if(location == 4){
					water = 'R';
				} else if(location == 6){
					water = 'L';
				} else if(location == 7){
					water = 'A';
				} else if(location == 8){
					water = 'K';
				} else if(location == 9){
					water = 'E';
				} else {
					water = '!';
				}
				cout << water;
			}
		}
		cout << endl;
	}
}

void GetLakeSAandV(double depths[82][78], double boundary, 
				   double& sa, double& v){
	double _v = 0;
	double _sa = 0;
	for(int i = 0; i < 82; i++){
		for(int j = 0; j < 78; j++){
			if(depths[i][j] <= boundary){
				_sa++;
				_v += depths[i][j] - boundary;
			}
		}
	}
	v = _v * -10;
	sa = _sa * 100;
}

void GetLakeExtreme(double depths[82][78], bool water, 
					double& x, double& y){
	double max = -90000;
	for(int i = 0; i < 82; i++){
		for(int j = 0; j < 78; j++){
			if(-water * depths[i][j] > max){
				x = i;
				y = j;
				max = -water * depths[i][j];
			}
		}
	}
}

int main(){
	ifstream fin("depths.txt");
	if(fin){
		double depths[82][78];
		LoadDepths(fin, depths);
		double x, y, sa = 0, v = 0;
		GetLakeExtreme(depths, true, x, y);
		GetLakeSAandV(depths, 0, sa, v);
		cout << fixed << setprecision(0) << "SA: " << sa 
			 << "m squared,  V: " << v << "m cubed"<< endl;
		GetLakeSAandV(depths, -25, sa, v);
		cout << "SA: " << sa << "m squared,  V: " << v 
			 << "m cubed"<< endl;
		DrawLake(depths, -25);
	}
}

/* Output:
SA: 352800m squared,  V: 8903080m cubed
SA: 326700m squared,  V: 8062880m cubed
 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
 . . . . . . . . . . . . . . . . . . . . . E!WATER!LAKE!WATER! . . . . . . . .
 . . . . . . . . . . . . . . . . . . . .WATER!LAKE!WATER!LAKE!WAT. . . .!. . .
 . . . . . . . . . . . . . . . . . WATER!LAKE!WATER!LAKE!WATER!LAKE. . .R. . .
 . . . . . . . . . . . . . KE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER . .E! . .
 . . . . . . . . . .LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!. .ER . .
 . . . . . TER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER! .KE!. .
 . . . . !LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE! .TER. .
 . . . .E!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER .AKE. .
 . . . TER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAK. .ATE. .
 . . . AKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WAT. .LA . .
 . KE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LA. .WA . .
 . .ER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!W . .!L . .
 . .KE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATE . . .!. . .
 . . ER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER . . . . . . . .
 . . KE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE . . . . . . . .
 . . . R!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATE . . . . . . . .
 . . . E!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAK . . . . . . . .
 . . . ER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!W . . . . . . . . .
 . . . .E!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER. . . . . . . . . .
 . . . .ER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAK . . . . . . . . . .
 . . . . . . . . LAKE! ATER!LAKE!WATER!LAKE!WATER!LAKE!W . . . . . . . . . . .
 .A. . . . . . . .ATER LAKE!WATER!LAKE!WATER!LAKE!WATER! . . . . . . . . . . .
 .ATE. . . . . . . AKE!WATER!LAKE!WATER!LAKE!WATER!LAKE! . . . . . . . . . . .
 .LAKE . . . . . .WATER!LAKE!WATER!LAKE!WATER!LAKE!WATE. . . . . . . . . . . .
 .WATE . . . . . .!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAK. . . . . . . . . . . .
 .!LAK . . . . . . .ATER!LAKE!WATER!LAKE!WATER!LAKE!WA . . . . . . . . . . . .
 .!WAT . . . . . . !LAKE!WATER!LAKE!WATER!LAKE!WATER!L . . . . . . . . . . . .
 .R!LAK. . . . . KE!WATER!LAKE!WATER!LAKE!WATER!LAKE!. . . . . . . . . . . . .
 .E!WATER!LA . WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER. . . . . . . . . . . . .
 .ER!LAKE!WA ER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE. . . . . . . . . . . . .
 . .!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WAT . . . . . . . . . . . . .
 . .R!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LA . . . . . . . . . . . . .
 . . !WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WA . . . . . . . . . . . . .
 . . R!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!L . . . . . . . . . . . . .
 . . .!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!W . . . . . . . . . . . . .
 . . .R!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER! . . . . . . . . . . . . .
 . . .E!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE! . . . . . . . . . . . . .
 . . . R!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER . . . . . . . . . . . . .
 . . . .!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE . . . . . . . . . . . . .
 . . . . !LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATE . . . . . . . . . . . . .
 . . . . . ATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAK . . . . . . . . . . . . .
 . . . . . L KE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WAT . . . . . . . . . . . . .
 . . . . . . TER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LA . . . . . . . . . . . . .
 . . . . . . AKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WA . . . . . . . . . . . . .
 . . . . . . ATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!L . . . . . . . . . . . . .
 . . . . . . . KE!WATER!LAKE!WATER!LAKE!WATER!LAKE!W . . . . . . . . . . . . .
 . . . . . . .ATER!LAKE!WATER!LAKE!WATER!LAKE!WATER! . . . . . . . . . . . . .
 . . . . . ER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE! . . . . . . . . . . . . .
 . . . . .AKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER . . . . . . . . . . . . .
 . . . . WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!. . . . . . . . . . . . .
 . . . ER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER. . . . . . . . . . . . .
 . . .AKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE. . . . . . . . . . . . .
 . . WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATE. . . . . . . . . . . . .
 . .R!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAK. . . . . . . . . . . . .
 . KE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WAT. . . . . . . . . . . . .
 .ATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LA. . . . . . . . . . . . .
 .LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WA. . . . . . . . . . . . .
 .WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!L. . . . . . . . . . . . .
 .!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE. . . . . . . . . . . . . .
 .!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATE. . . . . . . . . . . . . .
 .R!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAK. . . . . . . . . . . . . .
 .E!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WA . . . . . . . . . . . . . .
 . R!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER . . . . . . . . . . . . . . .
 . .!WATER!LAKE!WATER!LAKE!WATER!LAKE!WATER!LAK. . . . . . . . . . . . . . . .
 . . !LAKE!WATER!LAKE!WATER!LAKE!WATER!LAKE!WA . . . . . . . . . . . . . . . .
 . . . ATER!LAKE!WATER!LAKE!WATER!LAKE!WATER . . . . . . . . . . . . . . . . .
 . . . .AKE!WATER!LAKE!WATER!LAKE!WATER! . . . . . . . . . . . . . . . . . . .
 . . . . TER!LAKE!WATER!LAKE!WATER!LAKE. . . . . . . . . . . . . . . . . . . .
 . . . . . E!WATER!LAKE!WATER!LAKE!WA. . . . . . . . . . . . . . . . . . . . .
 . . . . . .R!LAKE!WATER!LAKE!WATER! . . . . . . . . . . . . . . . . . . . . .
 . . . . . . .WATER!LAKE!WATER!LAKE! . . . . . . . . . . . . . . . . . . . . .
 . . . . . . . . KE!WATER!LAKE!WAT . . . . . . . . . . . . . . . . . . . . . .
 . . . . . . . . . R!LAKE!WATE .L. . . . . . . . . . . . . . . . . . . . . . .
 . . . . . . . . . . .ATER!L . . . . . . . . . . . . . . . . . . . . . . . . .
 . . . . . . . . . . .LAK. . . . . . . . . . . . . . . . . . . . . . . . . . .
 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
 . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

*/