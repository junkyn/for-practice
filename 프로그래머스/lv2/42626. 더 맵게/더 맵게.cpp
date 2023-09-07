#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(),scoville.end());
    int count = 0;
    while(pq.top() < K && pq.size() > 1){
        int Least1 = pq.top(); pq.pop();
        int Least2 = pq.top(); pq.pop();
        int mix = Least1 + (Least2*2);
        count++;
        pq.push(mix);
    }
    if(pq.top() < K) return -1;
    return count;
}