#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    stack<pair<int,int>> dfs;
    dfs.push({0,0});
    while(!dfs.empty()){
        pair<int,int> p = dfs.top(); dfs.pop();
        if(p.second == numbers.size()){
            if(p.first == target){
                answer++;
            }
        }else{
            dfs.push(make_pair(p.first+numbers[p.second], p.second+1));
            dfs.push(make_pair(p.first-numbers[p.second],p.second+1));
        }
    }
    
    return answer;
}