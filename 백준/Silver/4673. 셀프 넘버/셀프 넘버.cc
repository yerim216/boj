#include <iostream>
using namespace std;

int selfNum(int n) {
	int num;
		if (n < 10) {
			num = 2 * n;
		}
		else if (n < 100) {
			num = n + n / 10 + n % 10;
		}
		else if (n < 1000) {
			num = n + n / 100 + (n % 100) / 10 + n % 10;
		}
		else if (n < 10000) {
			num = n + n / 1000 + (n % 1000) / 100 + (n % 100) /10 + n % 10;
			if (num >= 10000) {
				num = 0;
			}
		}
		else {
			num = 0;
		}
		return num;
}
int main() {
	int arr[10000] = { 0 };
	for(int i=1; i<10000; i++){
		arr[selfNum(i)] = selfNum(i);
	}
	for (int j = 1; j < 10000; j++) {
		if (arr[j] == 0 ) {
			cout << j << "\n";
		}
	}
}