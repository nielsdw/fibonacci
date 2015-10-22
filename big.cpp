#include "big.h"
using namespace std;
void big::extend(long long int value) {
	current = new chunk(value);
	current->next = first;
	first->prev = current;
	first = current;
}
void big::print() {
	current = first;
	cout << current->content;
	if (current->next) current = current->next; else return;
	while(current) { 
		printf("%018llu", current->content);
		current = current->next;
	}
}
big *sum(big *&a, big *&b) { 
	chunk *currentB = b->last;
	chunk *currentA = a->last;
	long long int carrier = 0;
	while (currentB) {
		currentB->content += currentA->content + carrier;
		carrier = 0;
		if (currentB->content > maxValue) {
			currentB->content -= maxValue;
			carrier = 1;
		}
		currentB = currentB->prev;
		currentA = currentA->prev;
	}
	if (currentA) b->extend(currentA->content + carrier); else if (carrier == 1) b->extend(carrier);
	return b; 
}
void fibo(int n) {
	big *a = new big(1);
	big *b = new big(1);
	big *c = new big;
	int t;
	for (t = 3; t <= n; t++) {
		c = sum(a, b);
		b = a;
		a = c;
	}
	a->print();
	delete a;
	delete b;
	delete c;
}
int main(int i, char *g[]) {
	if ((i==1) || (atoi(g[1]) > 10000000) || (atoi(g[1]) < 1)) { 
		cout << "Not a valid argument... (must be > 0 and < 1000000000)\n";
		return 0; 
	}
	time_t msec = time(NULL);
	fibo(atoi(g[1]));
	cout << "\nCalculation took: " << (time(NULL)) - msec << " seconds.\n";
	return 0;	
}
