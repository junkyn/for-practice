#include <iostream>
using namespace std;



int main() {
	int M, N;
	cin >> M >> N;
	int* arr = new int[N+1];
	if (N == 1) {
		return -1;
	}
	arr[1] = 0;
	for (int i = 2; i <= N; i++) {
		arr[i] = 1;
	}
	int count = 1;
	int startIdx = 2;
	while (count > 0) {
		count = 0;
		while (arr[startIdx] == 0) {
			startIdx++;
		}
		
		for (int i = 2; i*startIdx <= N; i++) {
			if (arr[startIdx * i] > 0) {
				arr[startIdx * i] = 0;
				count++;
			}
		}

		startIdx++;
	}
	for (int i = M; i <= N; i++) {
		if (arr[i] > 0) {
			cout << i << "\n";
		}
	}
}