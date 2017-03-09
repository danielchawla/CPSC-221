#include <iostream>

using namespace std;

int main(void) {
	int x = 5, y = 15;
	int * p1, *p2;
								// value of 	x			y			p1						p2
								//						5			15		uninit				uninit
	cout << "x: " << x << " y: " << y << " p1: uninit " << " p2: uninit " << endl;		

	p1 = &x;			//						5			15		address of x	uninit
	cout << "x: " << x << " y: " << y << " p1: " << p1 << " p2: uninit " << endl;

	p2 = &y;		  //						5			15		address of x	address of y
	cout << "x: " << x << " y: " << y << " p1: " << p1 << " p2: " << p2 << endl;

	*p1 = 6;		  //						6			15		address of x	address of y
	cout << "x: " << x << " y: " << y << " p1: " << p1 << " p2: " << p2 << endl;

	*p1 = *p2;		//						15 		15		address of x	address of y
	cout << "x: " << x << " y: " << y << " p1: " << p1 << " p2: " << p2 << endl;

	p2 = p1;		  //						15		15		address of x	address of x
	cout << "x: " << x << " y: " << y << " p1: " << p1 << " p2: " << p2 << endl;
	
	*p1 = *p2 + 10;	//					25		15		address of x	address of x
	cout << "x: " << x << " y: " << y << " p1: " << p1 << " p2: " << p2 << endl;
	return 0;
}
