#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> priorities, int location) {
    int idx = 0;
    int answer = 0;
    while(priorities[location]!=-1){
        int m = -1;
        for(int i : priorities){
            m = max(i,m);
        }
        if(priorities[idx] < m) (idx == priorities.size()-1) ? idx = 0 : idx++;
        else {priorities[idx] = -1; answer++;}
    }
    return answer;
}