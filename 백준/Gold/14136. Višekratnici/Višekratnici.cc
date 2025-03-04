#include <cstdio>
#include <vector>

#define maxn 100000
#define maxm 1000001

using namespace std;

int n, a[maxn];
int sito[maxm];

int dp[maxm];

vector< pair< int, int > > v;
int sol;

void load() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
}

void init_sito() { // eratostenovo sito, ali za svaki broj pamtimo koji je najmanji prosti faktor
	for (int i = 2; i < maxm; ++i)
		if (sito[i] == 0)
			for (int j = i; j < maxm; j += i)
				if (sito[j] == 0) sito[j] = i;
}

void gen(int m, int x, int k) { // rekurzivno generiramo sve djelitelje od m
	if (k == v.size()) {
		if (x != m) {

			if (dp[x] > sol) sol = dp[x];

		}
		return;
	}

	gen(m, x, k + 1);

	for (int i = 0; i < v[k].second; ++i) {
		x *= v[k].first;
		gen(m, x, k + 1);
	}
}

void rastavi(int x) { // rastavi svaki broj na faktore
	v.clear();
	for (; x > 1;) {
		int p = sito[x], k = 0;
		for (; x % p == 0; ++k) x /= p;
		v.push_back(make_pair(p, k));
	}
}

void solve() {
	for (int i = 0; i < n; ++i) {
		sol = 0;
		rastavi(a[i]);
		gen(a[i], 1, 0);
		if (sol + 1 > dp[a[i]]) dp[a[i]] = sol + 1;
	}

	sol = 0;
	for (int i = 0; i < maxm; ++i)
		if (sol < dp[i]) sol = dp[i];
	printf("%d\n", sol);

}

int main(void) {
	init_sito();
	load();
	solve();
	return 0;
}


