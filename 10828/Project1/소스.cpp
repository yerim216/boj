#include <iostream>
using namespace std;

class arrStack { //배열로 Stack 구현
public:
	int* arr; //배열 정의
	int capa; //배열 size 정의
	int t; //top 인덱스 정의

	arrStack(int capa) {
		this->capa = capa; 
		this->arr = new int[capa]; //q동적 배열 정의
		this->t = -1; //초기 top index 정의
	}

	~arrStack() {
		delete[arr]; //메모리 누수를 방지하기 위해 소멸자에서 delete
	}


	void push(int X) {
		arr[++t] = X;
	}
	int pop() {
		if (t == -1) {
			return -1;
		}
		else {
			return arr[t--];



		}
	}
	int size() {
		return t + 1;
	}
	int empty() {
		if (t == -1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	int top() {
		if (t == -1) {
			return -1;
		}
		else {
			return arr[t];
		}
	}
};
int main() {
	int N;
	cin >> N;
	arrStack a(10000);
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		if (s == "push") {
			int t;
			cin >> t;
			a.push(t);
		}
		else if (s == "pop") {
			cout << a.pop() << endl;
		}
		else if (s == "size") {
			cout << a.size() << endl;
		}
		else if (s == "empty") {
			cout << a.empty() << endl;
		}
		else if (s == "top") {
			cout << a.top() << endl;
		}

		
	}
}