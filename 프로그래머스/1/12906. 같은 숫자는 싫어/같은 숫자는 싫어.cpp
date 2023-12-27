#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    queue<int> Q;
    for(int n : arr)Q.push(n);
    while(!Q.empty()){
        if(answer.size()==0 || answer.back() != Q.front()){
            answer.push_back(Q.front());
            Q.pop(); continue;
        }
        if(answer.back()==Q.front()){
            Q.pop();
        }
    }
    
    return answer;
}