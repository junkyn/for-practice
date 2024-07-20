#include <iostream>
using namespace std;

int main() {
	int H, M;
	cin >> H >> M;
	
	M -= 45;

	if (M < 0) {
		H--;
		M += 60;
	}

	if (H < 0) {
		H += 24;
	}
	cout << H << " " << M;
}