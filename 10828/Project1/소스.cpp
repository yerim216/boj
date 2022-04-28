#include <iostream>
using namespace std;

class arrStack { //�迭�� Stack ����
public:
	int* arr; //�迭 ����
	int capa; //�迭 size ����
	int t; //top �ε��� ����

	arrStack(int capa) {
		this->capa = capa; 
		this->arr = new int[capa]; //q���� �迭 ����
		this->t = -1; //�ʱ� top index ����
	}

	~arrStack() {
		delete[arr]; //�޸� ������ �����ϱ� ���� �Ҹ��ڿ��� delete
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