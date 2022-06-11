#include <iostream>
using namespace std;

#define R 31
#define M 1234567891


long long hashing(char* str, int size) {
	long long hashNum = 0;
	for (int i = 0; i < size; i++) {
		long long charNum = str[i] - 'a' + 1;
		for (int j = 0; j < i; j++) {
			charNum = charNum * R % M;
		}
		hashNum = (hashNum + charNum) % M;
	}
	return hashNum;
	
}
int main() {
	int L;
	cin >> L;
	char* str = new char[L + 1];
	cin.ignore();
	cin.clear();
	cin.getline(str, L + 1);
	cout << hashing(str, L) << endl;

}
