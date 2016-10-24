//Zaeem Mohamed, Felix Wu
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//Felix
double areaTri(double s1, double s2, double s3)
{
	double s = (s1+s2+s3)/2.0;
	double area = sqrt((s-s1)*(s-s2)*(s-s3)*(s));
	return area;
}

//Felix
double areaQuad(double s1, double s2, double diagonal, 
				double s3, double s4)
{
	double area = areaTri(s1, s2, diagonal) 
				+ areaTri(s3, s4, diagonal);
	return area;
}

//Felix
double perimSector(double radious, double angle)
{
	double peremiter = 2.0*radious+angle/360*2*M_PI*radious;
	return peremiter;
}

//Felix
double areaSector(double radious, double angle)
{
	double area = M_PI*radious*radious*angle/360;
	return area;
}

//Zaeem
double perimTri(double a, double b, double c){
	return a + b + c;
}

//Zaeem
double perimQuad(double a, double b, double c, double d){
	return a + b + c + d;
}

//Zaeem
void calculateAndPrintCosts(int jobNum, bool isFenced,
							double area, double perimeter){
	double pavingCost = ceil(area) * 18.5;
	double fencingCost = ceil(perimeter) * 26.0 + 120.0;
	if(!isFenced){
		perimeter = 0;
		fencingCost = 0;
	}
	double subTotal = pavingCost + fencingCost + 35.0;
	double taxes = subTotal * 0.13;
	cout << fixed << setprecision(2) << jobNum << setw(14) 
		 << area << setw(14) << pavingCost << setw(14) 
		 << perimeter << setw(14) << fencingCost << setw(14)
		 << taxes << setw(14) << taxes + subTotal << endl;

}

//Zaeem
int main(){
	ifstream fin("jobs.txt");
	if(fin){
		int jobNum;
		bool isFenced;
		string shape;

		cout << fixed << setprecision(2) << "Job #" << setw(14) 
			 << "Paved Area" << setw(14) << "Paving Cost" 
			 << setw(14) << "Fenced Length" << setw(14) 
			 << "Fencing Cost" << setw(14) << "Taxes" 
			 << setw(14) << "Total Cost" << endl;

		while(fin >> jobNum >> isFenced >> shape){
			if(shape == "tri"){
				double a, b, c;
				fin >> a >> b >> c;

				calculateAndPrintCosts(jobNum, isFenced, 
					areaTri(a, b, c), perimTri(a, b, c));
			}else if(shape == "quad"){
				double a, b, diag, c, d;
				fin >> a >> b >> diag >> c >> d;

				calculateAndPrintCosts(jobNum, isFenced, 
					areaQuad(a, b, diag, c, d), 
					perimQuad(a, b, c, d));
			}else if(shape == "sect"){
				double radius, angle;
				fin >> radius >> angle;

				calculateAndPrintCosts(jobNum, isFenced, 
					areaSector(radius, angle), 
					perimSector(radius, angle));
			}
		}
	}
}

/* Output

Job #    Paved Area   Paving Cost Fenced Length  Fencing Cost
Taxes    Total Cost
7100        600.00      11100.00        120.00       3240.00
1868.75      16243.75
7101          9.00        166.50          0.00          0.00
26.20        227.69
7102          2.36         55.50          0.00          0.00
11.77        102.27
7103        784.00      14504.00        112.00       3032.00
2284.23      19855.23
7104        157.08       2923.00         51.42       1472.00
575.90       5005.90
7105         64.41       1202.50          0.00          0.00
160.88       1398.38
7106       2323.24      42994.00        192.80       5138.00
6261.71      54428.71
7107        197.04       3663.00          0.00          0.00
480.74       4178.74
7108        501.76       9287.00          0.00          0.00
1211.86      10533.86
7109         89.92       1665.00         38.21       1134.00
368.42       3202.42
7110         10.16        203.50          0.00          0.00
31.01        269.50
7111          3.90         74.00          9.00        354.00
60.19        523.19
7112         70.56       1313.50         33.60       1004.00
305.82       2658.32

*/