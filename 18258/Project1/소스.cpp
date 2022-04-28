#include <iostream>
using namespace std;
class Queue {
public:
	int capacity;
	int rear;
	int fron;
	int size;
	int* Q;

	Queue(int capacity) {
		this->capacity = capacity;
		fron = rear = size= 0;
		Q = new int[this->capacity];
		for (int i = 0; i < this->capacity; i++) {
			Q[i] = 0;
		}

	}
	~Queue() { delete[] Q; }
	int push(int X) {
		rear = (rear + 1) % capacity;
		Q[rear] = X;
		size++;
	}
	int pop() {
		if (rear == fron) {
			return -1;
		}
		else {
			int result = Q[fron];
			fron = (fron + 1) % capacity;
			Q[fron] = 0;
			size--;
			return result;
		}
	}
	int size() { return size; }
	int empty() {
		if (rear == fron) {
			return 1;
		}
		else {
			return 0;
		}
	}
	int front() { return Q[fron]; }
	int back() { return Q[rear]; }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	string S;
	Queue q(N);
	for (int i = 0; i < N; i++) {
		cin >> S;
		if (S == "push") {
			int a;
			cin >> a;
			q.push(a);
		}
		else if (S == "pop") {
			cout << q.pop() << endl;
		}
		else if (S == "empty") {
			cout << q.empty() << endl;
		}
		else if (S == "fron") {
			cout << q.front() << endl;
		}
		else if(S == "back") {
			cout << q.back() << endl;
		}
	}
}