#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, vector<int>> roadMap;
unordered_map<int, int> timeMap;
unordered_map<int, int> answerMap;

int calcTime(int idx) {
	if (answerMap[idx] >= 0) {
		return answerMap[idx];
	}

	int maxTime = timeMap[idx];
	for (int i = 0; i < roadMap[idx].size(); i++) {
		maxTime = max(maxTime, calcTime(roadMap[idx][i]) + timeMap[idx]);
	}
	answerMap[idx] = maxTime;
	return answerMap[idx];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N, K;
		cin >> N >> K;
		timeMap.clear();
		answerMap.clear();
		roadMap.clear();
		for (int j = 1; j <= N; j++) {
			int time;
			cin >> time;
			timeMap.insert({ j, time });
			answerMap.insert({ j, -1 });
		}

		for (int j = 0; j < K; j++) {
			int a, b;
			cin >> a >> b;
			roadMap[b].reserve(N);
			roadMap[b].push_back(a);

		}

		int W;
		cin >> W;

		cout << calcTime(W) << "\n";
	}


}
