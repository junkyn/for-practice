#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	queue<pair<int,int>> bfs;
	map<int, bool> visit;
	bfs.push(make_pair(N, 0));
	
	while (!bfs.empty()) {
		pair<int, int> po = bfs.front();
		visit.insert(make_pair(po.first, true));
		bfs.pop();
		if (po.first == K) {
			cout << po.second;
			return 0;
		}
		if (visit.find(po.first - 1) == visit.end()) {
			bfs.push(make_pair(po.first - 1, po.second + 1));
		}
		if (visit.find(po.first + 1) == visit.end()) {
			bfs.push(make_pair(po.first + 1, po.second + 1));
		}
		if (po.first * 2 < 2 * K - 1 &&  visit.find(po.first * 2) == visit.end()) {
			bfs.push(make_pair(2 * po.first, po.second + 1));
		}
	}
	return -1;
}