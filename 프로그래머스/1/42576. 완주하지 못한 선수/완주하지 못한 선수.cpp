#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string,int> M;
    for(string s : participant) if(M.count(s))M[s]++; else M.insert(make_pair(s,1));
    for(string s : completion) M[s]--;
    for(pair<string,int> p : M) if(p.second) return p.first;
}