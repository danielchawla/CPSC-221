#include <iostream>
using namespace std;

int arr[10];

void fill_array(int first_value, int increment);

int main(void) {
	fill_array(4,2);
	for ( int i = 0; i < 10; i++){
		cout << arr[i] << endl;
	}
	return 0;
}

void fill_array(int first_value, int increment){
	for (int i = 0; i < 10; i++){
		arr[i] = first_value + i*increment;
	}
}
