#include <iostream>
#include <map>
using namespace std;


int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;

	map<int, int> M;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		if (M.find(n) == M.end()) 
			M.insert({ n, 1 });
		else
			M[n]++;
	}

	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		if (M.find(n) == M.end())
			cout << 0 << " ";
		else
			cout << M[n] << " ";
	}
}