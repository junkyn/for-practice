#include <iostream>
#include <string>
using namespace std;
class Stack {
public:
	int p = 0;
	int a[50];
	void push(int x) {
		a[p++] == x;
	}
	int pop() {
		if (p == 0)return -1;
		return a[--p];
	}
	bool isEmpty() {
		if (p == 0)return true;
		return false;
	}
	void setNew() {
		int i = 0;
		while (a[i] == 1)a[i++] = 0;
		p = 0;
	}
};

int main() {
	int n;
	Stack S;
	cin >> n;
	for (int i = 0; i < n; i++) {
		bool check = true;
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '(') S.push(1);
			else if (str[j] == ')') {
				if (S.pop() == -1) check = false;
			}
		}
		if (!S.isEmpty() || !check) cout << "NO" << endl;
		else if (S.isEmpty()) cout << "YES" << endl;

		S.setNew();
	}
}