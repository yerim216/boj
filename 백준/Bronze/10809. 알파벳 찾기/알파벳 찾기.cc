#include <iostream>
using namespace std;
int main() {
	string s;
	cin >> s;
	int alphabet[26];
	for (int k = 0; k < 26; k++) {
		alphabet[k] = -1;
	}
	for (int i = 0; i < s.length(); i++) {
		if (alphabet[s[i]-'a'] == -1) {
			alphabet[s[i] - 'a'] = i;
		}
	}
	for (int j = 0; j < 26; j++) {
		cout << alphabet[j] << " ";
	}
}