#include <iostream>
#include <stack>

using namespace std;


int main() {
	int N;
	cin >> N;
	stack<int> S; 
	string answer;

	int j = 1;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		if (S.empty()) {
			S.push(j++);
			answer += "+\n";
		}

		int lastProcess = 0;

		while (!S.empty()) {
			if (S.top() == n) {
				S.pop();
				answer += "-\n";
				lastProcess = 0;
				break;
			}
			else if (S.top() > n) {
				if (lastProcess == 2) {
					break;
				}
				S.pop();
				answer += "-\n";
				lastProcess = 1;
			}
			else if (S.top() < n) {
				if (lastProcess == 1) {
					break;
				}
				S.push(j++);
				answer += "+\n";
				lastProcess = 2;
			}
		}

		if (lastProcess != 0) {
			cout << "NO";
			return 0;
		}
	}
	cout << answer;

}