#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> s1,s2,s3;
    int arr2[8] = {2,1,2,3,2,4,2,5};
    int arr3[10] = {3,3,1,1,2,2,4,4,5,5};
    vector<int> scores(3,0);
    for(int i = 0; i<answers.size(); i++){
        if(answers[i]==i%5+1) scores[0]++;
        if(answers[i]==arr2[i%8]) scores[1]++;
        if(answers[i]==arr3[i%10]) scores[2]++;
    }
    int maxV = -1;
    for(int n : scores) maxV = max(maxV,n);
    vector<int> answer;
    for(int i = 0; i<3; i++){
        if(scores[i] == maxV) answer.push_back(i+1);
    }

    
    return answer;
}