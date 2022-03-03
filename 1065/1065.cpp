//20220303
#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	if (N < 100) {
		cout << N << endl;
	}
	else if(N<1000)
	{
		int number =99, cnt = 100;

		while (true)
		{
	
			if (cnt/ 100 - (cnt % 100 / 10) == (cnt % 100 / 10) - (cnt % 100 % 10)) {
				number++;
				cnt++;
			}
			else 
			{
				
				if (cnt == N) {
					break;
				}
				cnt++;
				continue;
			}
			
			if (cnt > N) {
				break;
			}

			
		}
		cout << number << endl;

	}
	else if (N == 1000) {
		cout << 144 << endl;
	}
}
