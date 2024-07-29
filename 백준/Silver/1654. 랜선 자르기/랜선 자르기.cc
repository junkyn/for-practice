#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	int K;
	int N;

	vector<int> vec;
	cin >> K >> N;
	
	int max = 0;
	for (int i = 0; i < K; i++) {
		int lan;
		cin >> lan;
		vec.push_back(lan);
		if (lan > max) {
			max = lan;
		}
	}

	unsigned long long cut = 0;
	unsigned long long start = 0;
	unsigned long long end = max;
	unsigned long long mid;

	while (start <= end) {
		mid = (start + end) / 2;
		if (mid == 0) {
			break;
		}
		cut = 0;
		for (long unsigned int i = 0; i < vec.size(); i++) {
			cut += vec[i] / mid;
			if (cut > N) {
				break;
			}
		}

		if (cut >= N) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}

	}

	cout << end;

}