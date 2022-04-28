#include <iostream>
#include <vector>
using namespace std;

//»ğÀÔÁ¤·Ä
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
	bool empty() { return v.size() == 0; }
	void insert(int e) {
		vector<int>::iterator p = v.begin();
		isLess C;
		if (v.empty()) {
			v.insert(p, e);
		}
		else {
			while (p != v.end() && C(e, *p)) {
				++p;
			}
			v.insert(p, e);
		}
	}
	void min() {
		cout << v.back() << endl;
	}
	void removeMin() {
		v.pop_back();
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
		pq.min();
		pq.removeMin();
	

	}

}