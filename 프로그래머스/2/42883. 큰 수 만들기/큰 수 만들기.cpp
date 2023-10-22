#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    vector<int> N;
    for(char c : number)N.push_back(c-'0');
    string answer = "";
    int idx=0;
    k=number.size()-k;
    int l = k;
    for(int i = 0; i<l; i++){
        int greedy=0;
        for(int j = idx; j<N.size()-k+1; j++){
            if(greedy<N[j]){
                greedy = N[j]; idx = j;
            }
        }
        answer+=greedy+'0';
        N[idx] = -1;
        k--;
    }
    return answer;
}