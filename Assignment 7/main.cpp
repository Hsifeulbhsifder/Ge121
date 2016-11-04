//Eugene Wang
#include <cmath> 
#include <fstream> 

using namespace std; 

#include "ccc_win.h" 

void makingZigZag (double px, double py, double length, double depth){
	const int numPoint = 21;   		//make 21 points
	Point point[numPoint];
		
	for (int i = 0; i< numPoint; i ++)
	{
		if (i%2 == 0)
		{
			point[i] = Point(px+(length/(numPoint-1) )*(i), py);
		} 
		else 
		{
			point[i] = Point(px+ (length/(numPoint-1) )*(i), py-depth);				
		} 
		if (i>0)
		{		
			Line lin(point [i-1], point[i]);
			cwin << lin; 
		}			
	}
}

void makingcircle (double px, double py, double length){
	const int numPoint = 1001;   		//make 21 points
	int centerpoint  = numPoint/2.0;
	Point point[numPoint];
	
	
		
	for (int i = 0; i< numPoint; i ++)
	{
		point[i] = Point ( px + i * length/ (numPoint-1)    , py +  sqrt ( pow((length/2), 2) -  pow ( (i-centerpoint)*length/ (numPoint)  ,2) ) );
			
		if (i>0)
		{		
			Line lin(point [i-1], point[i]);
			cwin << lin; 
		}			
	}
}





int ccc_win_main() {
	
	Point p0;	
	
	
	//actual code
	int a = 0;
	while (! (a>0&&a<20)){
		a = cwin.get_int("how many shapes do you want?");
	}
	
	for (int i = 0; i < a; i ++){
	 
		p0 = cwin.get_mouse("Click for Drawing");
		double px = p0.get_x();
		double py = p0.get_y();
		
		
		
		Point p1(px, py-5), p2(px+5, py), p3(px+5, py-5);
		
		Line 
			lin1(p0, p1), 
			lin2(p0, p2),
			lin3(p2, p3)
		;
		
		Circle crc(Point (px+2.5, py), 2.5 );
			
		
		
		makingZigZag(px, py-5, 5 , 1);
		makingcircle(px, py, 5);
		makingcircle(px+1.4, py+1.4,  1);
		makingcircle(px+2.6, py+1.4,  1);
		
		makingZigZag(px+1.4, py+0.8, 2.2 , 0.3);
		
		Circle crc0(Point (px+1.9, py+ 1.4), 0.2 );
		Circle crc1(Point (px+3.1, py+ 1.4), 0.2 );
		
		
		
		
		cwin << p0 << p1 << p2 << p3;
		cwin << lin1 << lin2 << lin3;
		cwin << crc0 <<crc1;
		
		
	
	}
	
	
	// Insert program code here 
	return 0;
}
