#include <iostream>
using namespace std;

long long pow(long long x, long long y)
{
	long long result = 1;
	for (long long i = 0; i < y; i++)
	{
		result *= x;
	}
	return result;
}
int main() {
	char order[34];
	cin.getline(order, 34, '\n');
	long long N = 0;
	long long OrderIdx = 2;
	if (order[1] >= '0' && order[1] <= '9')
	{
		N = ((order[0] - '0') * 10 + (order[1] - '0'));
		OrderIdx = 3;
	}
	else
		N = order[0] - '0';
	long long label = pow(2, N + 1);

	if (!(order[OrderIdx] == 'L' || order[OrderIdx] == 'R')) {
		cout << label - 1;
	}
	else {
		long long curNum = 1;

		while (order[OrderIdx] == 'L' || order[OrderIdx] == 'R') {
			if (order[OrderIdx] == 'L')
				curNum = curNum * 2;
			else curNum = curNum * 2 + 1;

			OrderIdx++;
		}
		label -= curNum;
		cout << label;
	}
	
}