#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int* S = new int[n];
    for(int i = 0; i<n; i++){
        S[i]=1;
    }
    for(int i : lost){
        S[i-1]--;
    }
    for(int i : reserve){
        S[i-1]++;
    }
    int answer= 0;
    for(int i = 0; i<n; i++){
        if(S[i] == 0){
            int k;
            if(((k=i-1)>=0 && S[k] == 2) || ((k=i+1)<n && S[k] == 2)){
                S[k]--; S[i]++;
            }
        }
        if(S[i] >= 1)
            answer++;
    }
    return answer;
}