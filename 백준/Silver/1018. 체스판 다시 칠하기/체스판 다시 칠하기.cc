#include <iostream>
#include <queue>
using namespace std;


int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int N, M;

	cin >> N >> M;

	char** arr = new char* [N];
	for (int i = 0; i < N; i++) {
		arr[i] = new char[M];
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int minX = 3;
	int maxX = M - 5;
	int minY = 3;
	int maxY = N - 5;

	priority_queue<int, vector<int>, greater<int>> PQ;
	for (int i = minY; i <= maxY; i++) {
		for (int j = minX; j <= maxX; j++) {
			int dot = 0;
			bool startWithB = arr[i - 3][j - 3] == 'B';
			for (int k = i - 3; k <= i + 4; k++) {
				for (int l = j - 3; l <= j + 4; l++) {
					if (startWithB) {
						if ((k - i + 3 + l - j + 3) % 2 == 0&& arr[k][l] != 'B') {
							dot++;
						}
						else if ((k - i + 3 + l - j + 3) % 2 == 1 && arr[k][l] != 'W') {
							dot++;
						}
					}
					else {
						if ((k - i + 3 + l - j + 3) % 2 == 0 && arr[k][l] != 'W') {
							dot++;
						}
						else if ((k - i + 3 + l - j + 3) % 2 == 1 && arr[k][l] != 'B'){
							dot++;
						}
					}
				}
			}
			PQ.push(min(dot, 64 - dot));
		}
	}
	
	cout << PQ.top();
}