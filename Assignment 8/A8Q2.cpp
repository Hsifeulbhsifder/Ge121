#include <iostream>
#include <cmath>

using namespace std;

class Fraction{
private:

	int num;
	int den;

public:

	Fraction(){
		(*this).num = 1;
		(*this).den = 2;
	}

	Fraction(int num, int den){
		if(den < 0){
			(*this).num = -num;
			(*this).den = -den;
		} else{
			(*this).num = num;
			(*this).den = den;			
		}
	}

	int getNum() const{
		return num;
	}
	void setNum(int num){
		(*this).num = num;
	}
	int getDen() const{
		return den;
	}
	void setDen(int den){
		if(den < 0){
			num = -num;
			(*this).den = -den;
		}else{
			(*this).den = den;
		}
	}

	double precisionRound(int precision) const{
		return round(pow(10, precision) 
			   * (double(num)/den)) / pow(10, precision);
	}

	bool isExactlyEqual(Fraction const & other) const{
		return (num == other.num && den == other.den);
	}

	void output() const{
		cout << num << "/" << den << endl;
	}

};

int main(){
	Fraction f(2,-3);
	cout << f.precisionRound(3) << endl;
	f.output();

	Fraction a;
	a.output();
	if(a.isExactlyEqual(f)){
		cout << "Equals" << endl;
	} else {
		cout << "Not Equals" << endl;
	}

	a.setNum(2);
	a.setDen(-3);
	a.output();

	if(a.isExactlyEqual(f)){
		cout << "Both fractions equal " << a.getNum() 
			 << "/" << a.getDen() << endl;
	} else {
		cout << "Not Equals" << endl;
	}

	Fraction r(7312, 22423);
	cout << r.precisionRound(0) << endl;
	cout << r.precisionRound(1) << endl;
	cout << r.precisionRound(2) << endl;
	cout << r.precisionRound(3) << endl;
	cout << r.precisionRound(4) << endl;
	cout << r.precisionRound(5) << endl;
	cout << r.precisionRound(6) << endl;
	r.output();

}