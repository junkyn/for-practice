#include <iostream>
using namespace std;

int Max;
class Object {
public: 
	int w; int v;
	Object() { w = 0; v = 0; }
	Object(int a, int b) {
		w = a; v = b;
	}
};
int DP[101][100001];
Object* bag;


int main() {
	int n;
	cin >> n >> Max;
	bag = new Object[n];
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		bag[i] = Object(a, b);
	}
	for (int i = 1; i <= Max; i++) {
		for (int j = 1; j <= n; j++) {
			if (i >= bag[j-1].w) {
				DP[j][i] = max(DP[j - 1][i], DP[j - 1][i - bag[j-1].w] + bag[j-1].v);
			}
			else {
					DP[j][i] = DP[j - 1][i];
				
			}
		}
	}
	cout << DP[n][Max];

}