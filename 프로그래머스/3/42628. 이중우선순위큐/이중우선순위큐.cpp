#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<int,vector<int>,greater<int>> maxQ;
    priority_queue<int,vector<int>,less<int>> minQ;
    map<int,bool> Del;
    int n;
    for(string s : operations){
        switch(s[0]){
            case 'I':
                n = stoi(s.substr(2));
                minQ.push(n);
                Del.insert(make_pair(n,false));
                maxQ.push(n);
                break;
            case 'D':
                if(s[2]=='1'){
                    if(minQ.empty()) break;
                    n = minQ.top(); minQ.pop();
                    Del[n] = true;
                }else{
                    if(maxQ.empty()) break;
                    n = maxQ.top(); maxQ.pop();
                    Del[n] = true;
                }
        }
        while(!minQ.empty()&&Del[minQ.top()]) minQ.pop();
        while(!maxQ.empty()&&Del[maxQ.top()]) maxQ.pop();
        if(minQ.empty() || maxQ.empty()){
            while(!minQ.empty()) minQ.pop();
            while(!maxQ.empty()) maxQ.pop();
        }
    }
    if(minQ.empty() || maxQ.empty()) return {0,0}; 
    return {minQ.top(),maxQ.top()};
}