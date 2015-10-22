#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
using namespace std;
long long unsigned* resize(long long unsigned c[], int length) {
 	long long unsigned *b = new long long unsigned[length*2];
	for (int r=0 ; r < length ; r++) b[r] = c[r];
	for (int r=length ; r < length * 2 ; r++) b[r] = 0;
	delete c;
	return b;
}
void Fiblarge(int n) {
	long long unsigned arrayCounter = 0, currentArrayLength = 1, carry = 0;
	int i = 0;
	int totalArrayLength = 1;
	long long unsigned *a = new long long unsigned[totalArrayLength] ; a[0] = 1;
	long long unsigned *b = new long long unsigned[totalArrayLength] ; b[0] = 1;
	long long unsigned elementSize = 1000000000000000000L;
	for (i = 3; i <= n; i++) {
		for (arrayCounter = 0; arrayCounter < currentArrayLength; arrayCounter++) {
			long long unsigned sum = a[arrayCounter] + b[arrayCounter] + carry;
			carry = 0;
			b[arrayCounter] = a[arrayCounter];
			a[arrayCounter] = sum;
			if (a[arrayCounter] > elementSize) {
				a[arrayCounter] -= elementSize;
				carry = 1;
			}
		}
		if (carry > 0) { 
			if (currentArrayLength == totalArrayLength){ 
				a = resize(a,totalArrayLength);
				b = resize(b,totalArrayLength);
				totalArrayLength *= 2;
			}
			a[currentArrayLength++] = 1;
		}
		carry = 0;
	}
	i = currentArrayLength - 1;
	cout << a[i--];
	while (i >= 0) printf("%018llu",a[i--]);
	cout << endl;
}
int main(int i, char *g[]){
	if ((i==1) || (atoi(g[1]) > 10000000) || (atoi(g[1]) < 1)) { 
		cout << "Not a valid argument... (must be > 0 and < 1000000000)" << endl;
		return 0; 
	}
	time_t msec = time(NULL);
	Fiblarge(atoi(g[1]));
	cout << endl <<"Calculation took: " << (time(NULL)) - msec << " seconds." << endl;
	return 0;
}
