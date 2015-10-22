#include <iostream>
#include <stdlib.h>
#include <cstdio>
const long long int maxValue = 1000000000000000000;
struct chunk {
		long long int content;
		chunk *next;
		chunk *prev;
		chunk() { content = 0; next = NULL; prev = NULL; }
		chunk(long long int value) { content = value; next = NULL; prev = NULL; }
};
struct big {
		chunk *first;
		chunk *last;
		chunk *current;
		big() { first = new chunk; first->next = NULL; first->prev = NULL; last = first; }
		big(long long int init_value) { first = new chunk(init_value); first->next = NULL; first->prev = NULL; last = first; }
		~big() {
			chunk *destroy = new chunk;
			destroy = first;
			while (destroy) {
				if (destroy->prev) delete destroy->prev;
				destroy = destroy->next;
			}
			delete destroy;
		}
		void extend(long long int value);
		void print();
};

