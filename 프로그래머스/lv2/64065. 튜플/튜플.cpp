#include <string>
#include <vector>
#include <cctype>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<char> c(s.begin(),s.end());
    vector<vector<int>> V(1);
    int idx = 0;
    string tmp = "";
    for(int i = 0; i<c.size(); i++){
        if(isdigit(c[i])!=0){
            tmp+=c[i];
        }else if(i>1 && c[i] == '{'){
            V.resize((++idx)+1);
        }else if(tmp!=""){
            V[idx].push_back(stoi(tmp));
            tmp="";
        }
    }
    int count = 0;
    for(vector<int> v : V){
        if(v.size()>0) count++;
    }
    sort(V.begin(),V.end(), [](vector<int> v1, vector<int> v2) -> bool{return v1.size()>v2.size();});
    V.resize(count);
    sort(V.begin(),V.end(), [](vector<int> v1, vector<int> v2) -> bool{return v1.size()<v2.size();});
    vector<int> answer;
    for(vector<int> v : V){
        for(int i : answer){
            for(int j = 0; j<v.size(); j++){
                if(i==v[j]){
                    v.erase(v.begin()+j);
                }
            }
        }
        for(int i : v){
            answer.push_back(i);
        }
    }
    return answer;
}