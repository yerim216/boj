#include <iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	

	for (int i = 0; i < T; i++) {
		int A;
		int B;
		cin >> A >> B;
		int arrA[11]{ 0 };
		int arrB[11]{ 0 };

		arrA[0] = A;
		arrB[0] = B;
		int index = 1;
		
		while (A > 1) {
			if (A % 2 == 1)
				A = (A - 1) / 2;

			else
				A = A / 2;

			arrA[index] = A;
			index++;

		}

		index = 1;
		while (B > 1) {
			if (B % 2 == 1)
				B = (B - 1) / 2;

			else
				B = B / 2;

			arrB[index] = B;
			index++;

		}
	
		int max = 1;
		for (int a = 0; a < 10; a++) {
			for (int b = 0; b < 10; b++) {
				if (arrA[a] == arrB[b]) {
					if (max < arrA[a]) {
						max = arrA[a];
						break;
					}
				}

			}
		}

			cout << max * 10 << "\n";

		
	}
	return 0;
}