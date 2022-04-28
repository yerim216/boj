#include <iostream>
#include <vector>
using namespace std;
//선택정렬
class isLess {
public:
	bool operator()(const int a, const int b) {
		if (a < b) {
			return true;
		}
		else {
			return false;
		}
	}
};
class PQ {
private:
	vector<int> v;

public:
	void insert(int e) {
		v.push_back(e);
	}
	void removeMin() {
		vector<int>::iterator p = v.begin();
		isLess C;
		int m_value = *v.begin();
		for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
			if (!C(m_value, *iter)) {
				m_value = *iter;
				p = iter;
			}
		}
		cout << *p << endl;
		v.erase(p);
		
	}
};
int main() {
	int N;
	cin >> N;
	PQ pq;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		pq.insert(n);
	
	}
	for (int i = 0; i < N; i++) {
		pq.removeMin();

	}
}