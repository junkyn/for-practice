#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		vector<int> vec;
		
		for (char c : input) {
			vec.push_back(c - '0');
		}
		
		int reverseMid = vec.size() / 2;
		for (int j = reverseMid; j < vec.size(); j++) {
			if (vec[j] < vec[vec.size() - 1 - j]) {
				break;
			}
			if (vec[j] > vec[vec.size() - 1 - j]) {
				int idx = vec.size() / 2 - (vec.size() % 2 == 0);
				vec[idx]++;
				while (vec[idx] == 10) {
					vec[idx] = 0;
					vec[idx - 1]++;
					idx--;
				}
				break;
			}
		}

		string answer = "";
		
		for (int j = 0; j < vec.size(); j++) {
			answer += (j < vec.size() / 2 ? vec[j] + '0' : vec[vec.size() - j - 1] + '0');
		}
		cout << answer << "\n";
	}
}