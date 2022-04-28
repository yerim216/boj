#include <iostream>
using namespace std;
class Queue { //�迭�� ť ����
public:
	int capacity; //ť�� �뷮
	int rear; 
	int fron; //front�� �ƴ� fron�� ����. ����Լ��� ������ �̸��� ������ � ���� ȣ���ϴ���
	//���� ���� �߻�
	int siz; //���� ������ size�� �ƴ� siz�� ����
	int* Q; 

	Queue(int capacity) {
		this->capacity = capacity;
		fron = rear = siz = 0;
		Q = new int[this->capacity];


	}
	~Queue() { delete[] Q; } //�޸� ���� ������ ���� �Ҹ��ڿ��� Q delete
	void push(int X) {
		rear = (rear + 1) % capacity; //������ ������ ����� ����
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
	int front() {
		if (siz == 0) {
			return -1;
		}
		else { return Q[fron + 1]; }
	}
	int back()
	{
		if (siz == 0) {
			return -1;
		}
		else { return Q[rear]; }
	}
	};

	int main() {
		ios::sync_with_stdio(false); //�ð��ʰ��� ���� ���� ����
		cin.tie(NULL);
		cout.tie(NULL);
		int N;
		cin >> N;
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
				cout << q.pop() << "\n";
			}
			else if (S == "empty") {
				cout << q.empty() << "\n";
			}
			else if (S == "front") {
				cout << q.front() << "\n";
			}
			else if (S == "back") {
				cout << q.back() << "\n";
			}
			else if (S == "size") {
				cout << q.size() << "\n";
			}
		}
	}
