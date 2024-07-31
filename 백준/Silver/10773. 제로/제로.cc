#include <iostream>
#include <stack>
using namespace std;


int main() {
	int N;
	cin >> N;
	stack<int> st;
	int sum = 0;
	
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		if (n == 0) {
			if (st.empty())
				continue;
			sum -= st.top();
			st.pop();
		}
		else {
			sum += n;
			st.push(n);
		}
	}

	cout << sum;
}