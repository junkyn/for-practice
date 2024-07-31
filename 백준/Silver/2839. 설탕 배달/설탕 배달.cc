#include <iostream>
#include <queue>
using namespace std;


int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int N;
	cin >> N;

	int n = N / 5;
	int m = N - n * 5;
	
	while (m % 3 > 0) {
		n--;
		if (n < 0) {
			cout << -1;
			return 0;
		}
		m = N - n * 5;
	}


	cout << n + m / 3;
}