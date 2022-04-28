#include <iostream>
using namespace std;
class Heap {
public:
	int* arr;
	int idx;

	Heap(int N) {
		arr = new int[N];
		arr[0] = 0;
		idx = 0;
	}
	void insert(int X){
		arr[++idx] = X;
	}
	int removeMin() {
		return arr[idx--];

	}
};