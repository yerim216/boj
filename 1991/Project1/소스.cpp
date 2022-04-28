#include <iostream>
using namespace std;

int binaryTree[26]{ 0 };
void PreOrder(int root, int rootIdx) {
	char cur = '0';
	for (int i = rootIdx; i < 26; i++)
	{
		if (binaryTree[i] == root)
		{
			cur = i + 'A';
			break;
		}
	}
}
void inOrder() {}
void postOrder() {}
int main()
{
	int N;
	cin >> N;

	binaryTree[0] = 1;

	for (int n = 0; n < N; n++)
	{
		char tree;
		cin >> tree;

		int cur = tree - 'A';

		cin >> tree;
		if (tree != '.')
		{
			int left = tree - 'A';
			binaryTree[left] = binaryTree[cur] * 2;
		}

		cin >> tree;
		if (tree != '.')
		{
			int right = tree - 'A';
			binaryTree[right] = binaryTree[cur] * 2 + 1;
		}
	}

	preOrder(1, 0);
	cout << '\n';
	inOrder(1, 0);
	cout << '\n';
	postOrder(1, 0);
}