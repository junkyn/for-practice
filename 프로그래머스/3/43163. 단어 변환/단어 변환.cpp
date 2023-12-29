#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<string,int>> bfs;
    if(find(words.begin(),words.end(),target)==words.end())return 0;
    for(string s : words){
        int count=0;
        for(int i = 0; i < s.size(); i++){
            if(s[i]!=begin[i]) count++;
            if(count>1) break;
        }
        if(count==1){
            if(s==target) return 1;
            bfs.push(make_pair(s,1)); 
        }
    }
    while(!bfs.empty()){
        pair<string,int> node = bfs.front();bfs.pop();
        for(string s : words){
            int count = 0;
            for(int i = 0; i<s.size(); i++){
                if(s[i]!=node.first[i]) count++;
                if(count>1) break;
            }
            if(count==1){
                if(s==target) return node.second+1;
                bfs.push(make_pair(s,node.second+1));
            }
        }
    }
    return 0;
}