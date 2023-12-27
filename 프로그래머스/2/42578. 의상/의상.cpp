#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string,int> M;
    for(vector<string> v : clothes){
        if(M.find(v[1]) == M.end()){
            M.insert(make_pair(v[1],2));
        }
        else{
            M[v[1]]++;
        }
    }
    int answer = 1;
    for(auto iter = M.begin(); iter!=M.end();iter++){
        answer *= iter->second;
    }
    return answer-1;
}