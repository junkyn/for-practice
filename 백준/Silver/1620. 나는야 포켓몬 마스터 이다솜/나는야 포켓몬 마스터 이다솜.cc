#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	unordered_map<string, int> nameMap;
	unordered_map<int, string> indexMap;

	for (int i = 1; i <= N; i++) {
		string input;
		cin >> input;
		nameMap.insert({ input, i });
		indexMap.insert({ i, input });
	}

	for (int i = 0; i < M; i++) {
		string input;
		cin >> input;
		int index = atoi(input.c_str());
		if (index > 0) {
			cout << indexMap[index];
		}
		else {
			cout << nameMap[input];
		}
		cout << "\n";
	}
}