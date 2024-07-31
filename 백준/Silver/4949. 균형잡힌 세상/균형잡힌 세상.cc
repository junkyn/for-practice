#include <iostream>
#include <stack>
using namespace std;


int main() {
	while (true) {
		char s[101];
		cin.getline(s, 101);
		if (s[0] == '.') 
			break;

		stack<char> st;
		
		for (int i = 0; i < 101; i++) {
			if (s[i] == '.') {
				if (st.empty())
					cout << "yes" << '\n';
				else 
					cout << "no" << '\n';
				break;
			}
			if (s[i] == '(' || s[i] == '[') {
				st.push(s[i]);
			}
			else if (s[i] == ')') {
				if (st.empty() || st.top() != '(') {
					cout << "no" << '\n';
					break;
				}
				else {
					st.pop();
				}
			}
			else if (s[i] == ']') {
				if (st.empty() || st.top() != '[') {
					cout << "no" << '\n';
					break;
				}
				else {
					st.pop();
				}
			}
		}
	}
}