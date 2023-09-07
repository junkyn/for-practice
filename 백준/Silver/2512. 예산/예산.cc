#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getSum(vector<int> v) {
	int s = 0;
	for (int n : v) {
		s += n;
	}
	return s;
}
int main() {
	int n; cin >> n;
	int max;
	vector<int> B(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> B[i];
		sum += B[i];
	}
	sort(B.begin(), B.end());
	cin >> max;
	int top = B[B.size()-1];
	while (sum > max) {
		top--;
		for (int i = 0; i < B.size(); i++) {
			if (B[i] > top) {
				B[i] = top;
			}
		}
		sum = getSum(B);
	}
	cout << top;
	return 0;
}
