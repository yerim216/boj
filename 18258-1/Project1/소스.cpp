#include <iostream>
using namespace std;
class Queue { //배열로 큐 정의
public:
	int capacity; //큐의 용량
	int rear; 
	int fron; //front가 아닌 fron로 정의. 멤버함수와 변수가 이름이 같으면 어떤 것을 호출하는지
	//몰라 에러 발생
	int siz; //같은 이유로 size가 아닌 siz로 정의
	int* Q; 

	Queue(int capacity) {
		this->capacity = capacity;
		fron = rear = siz = 0;
		Q = new int[this->capacity];


	}
	~Queue() { delete[] Q; } //메모리 누수 방지를 위해 소멸자에서 Q delete
	void push(int X) {
		rear = (rear + 1) % capacity; //나머지 연산을 사용해 대입
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
		ios::sync_with_stdio(false); //시간초과를 막기 위해 삽입
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
