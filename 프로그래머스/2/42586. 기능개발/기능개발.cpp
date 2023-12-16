#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    while(progresses.size() > 0){
        int i = 0;
        bool input = false;
        while(i<progresses.size()){
            progresses[i]+=speeds[i];
            if(progresses[i]>=100 && i==0){
                
                if(!input){
                    answer.push_back(1);
                    input = true;
                }else{
                    answer[answer.size()-1]++;
                }
                progresses.erase(progresses.begin());
                speeds.erase(speeds.begin());
                i--;
            }
            i++;
        }
    }
    return answer;
}