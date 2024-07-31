#include <iostream>
#include <vector>
using namespace std;


int main() {
	int N, K;
	cin >> N >> K;

	vector<int> vec;
	for (int i = 1; i <= N; i++) {
		vec.push_back(i);
	}
	int idx = 0;
	cout << "<";
	while (!vec.empty()) {
		idx = (idx + K - 1) % vec.size();
		cout << vec[idx];
		vec.erase(vec.begin() + idx);
		if (!vec.empty()) {
			cout << ", ";
		}
	}
	cout << ">";
}