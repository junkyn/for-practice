#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int N;
int except;
int sum;
priority_queue<int, vector<int>, greater<int>> minQ;
priority_queue<int> maxQ;

void func(int n) {
	if (except > 0 && minQ.size() >= except && n > minQ.top()) {
		int m = minQ.top();
		minQ.pop();
		minQ.push(n);
		func(m);
	}
	else if (except > 0 && minQ.size() < except) {
		minQ.push(n);
	}
	else if (except > 0 && maxQ.size() >= except && n < maxQ.top()) {
		int m = maxQ.top();
		maxQ.pop();
		maxQ.push(n);
		func(m);
	}
	else if (except > 0 && maxQ.size() < except) {
		maxQ.push(n);
	}
	else {
		sum += n;
	}
}

int main() {
	cin >> N;
	
	if (N == 0) {
		cout << 0;
		return 0;
	}

	except = round(N * 0.15f);

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		func(n);
	}
	
	cout << round((float)sum / (float)(N - 2 * except));
}