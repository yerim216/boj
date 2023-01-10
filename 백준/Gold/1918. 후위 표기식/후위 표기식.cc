#include <iostream>
#include <stack>

using namespace std;
int main() {
	stack<char> opera;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '('){
			opera.push(s[i]);
		}
		else if (s[i] == '*' || s[i] == '/') {
			if (opera.empty() || opera.top() == '('|| opera.top() == '+' || opera.top() == '-') {
				opera.push(s[i]);
			}
			else{
				cout << opera.top();
				opera.pop();
				while (!opera.empty() && (opera.top() == '*' || opera.top() == '/')) {
					cout << opera.top();
					opera.pop();
				}
				opera.push(s[i]);


			}
		}
		else if (s[i] >= 'A' && s[i] <= 'z') {
			cout << s[i];
		}
		else if (s[i] == '+' || s[i] == '-') {
			if (opera.empty() || opera.top()=='(') {
				opera.push(s[i]);
			}
			else {
				cout << opera.top();
				opera.pop();
				while (!opera.empty() && opera.top()!='('){
					cout << opera.top();
					opera.pop();
				}
				opera.push(s[i]);
			}
		}
		else if (s[i] == ')') {
			while (opera.top() != '(') {
				cout << opera.top();
				opera.pop();
			}
			opera.pop();
		}


	}
	while (!opera.empty()) {
		cout << opera.top();
		opera.pop();
	}

	return 0;

}
