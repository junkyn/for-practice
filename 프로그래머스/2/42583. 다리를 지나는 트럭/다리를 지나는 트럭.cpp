#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> bridge;
    int curWeight = 0;
    
    while(truck_weights.size()>0 || curWeight>0){
        answer++;
        if(bridge.size()==bridge_length){
            curWeight-=bridge.front();
            bridge.pop();
        }
        if(truck_weights.size()>0 && curWeight+truck_weights[0]<=weight){
            curWeight+=truck_weights[0];
            bridge.push(truck_weights[0]);
            truck_weights.erase(truck_weights.begin());
        }
        else{
            bridge.push(0);
        }
    }

    return answer;
}