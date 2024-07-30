#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

int main() {
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	map<int, int> countMap;
	int N;
	cin >> N;
	double sum = 0;
	int max = -4000;
	int min = 4000;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		sum += n;
		max = std::max(max, n);
		min = std::min(min, n);
		if (minHeap.size() == maxHeap.size()) {
			maxHeap.push(n);
		}
		else {
			minHeap.push(n);

		}
		if ((!maxHeap.empty() && !minHeap.empty()) && maxHeap.top() > minHeap.top()) {
			int n1 = maxHeap.top();
			int n2 = minHeap.top();
			minHeap.pop();
			maxHeap.pop();
			maxHeap.push(n2);
			minHeap.push(n1);
		}

		if (countMap.find(n) == countMap.end()) {
			countMap.insert(make_pair(n, 1));
		}
		else {
			countMap[n]++;
		}


	}
	
	vector<pair<int, int>> vec(countMap.begin(), countMap.end());
	


	sort(vec.begin(), vec.end(), cmp);
	
	int mode = vec.size() > 1 && vec[0].second == vec[1].second ? vec[1].first : vec[0].first;
	
	int avg = round(sum / N);
	std::cout << avg << "\n";
	std::cout << maxHeap.top() << "\n";
	std::cout << mode << "\n";
	std::cout << max - min << "\n";


}