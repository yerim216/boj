#include <iostream>
using namespace std;
class arrStack {
public:
	double* arr;
	int top;
	int size;

	arrStack(int size) {
		arr = new double[size];
		top = -1;
		this->size = size;
	}
	void push(char X) {
		arr[++top] = X;
	}
	char pop() {
		if (top == -1) {
		}
		else {
			return arr[top--];
		}
	}
	
};

int main() {
	int N;
	string s;
	cin >> N >> s;
	arrStack as(N);
	
	int n;
	cin >> n;
	for (int j = 0; j < N; j++) {
		int *nArr = new int[N];
		nArr[j] = n;
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'A' || s[i] <= 'Z') {
			as.push(s[i]);
		}
		else  {
			char b = as.pop();
			char a = as.pop();
			
			if (s[i] == '+') {
				cout << 
			}
		}
		
	}
}