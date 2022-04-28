#include <iostream>
using namespace std;
class Queue {
public:
	int capacity;
	int rear;
	int fron;
	int siz;
	int* Q;

	Queue(int capacity) {
		this->capacity = capacity;
		fron = rear = siz = 0;
		Q = new int[this->capacity];


	}
	~Queue() { delete[] Q; }
	void push(int X) {
		rear = (rear + 1) % capacity;
		Q[rear] = X;
		siz++;

	}
	int pop() {
		if (siz == 0) {
			return -1;
		}
		else {
			fron = (fron + 1) % capacity;
			int result = Q[fron];
			siz--;
			return result;
		}
	}
	int size() { return siz; }
	int empty() {
		if (siz == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	int front() { return Q[fron + 1]; }
	int back() { return Q[rear]; }
};