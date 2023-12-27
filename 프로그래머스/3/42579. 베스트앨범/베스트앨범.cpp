#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,vector<pair<int,int>>> m;
    map<string,int> mm;
    for(int i = 0; i<genres.size(); i++){
        mm[genres[i]]+=plays[i];
        if(m[genres[i]].size()==1){
            m[genres[i]].push_back(make_pair(i,plays[i]));
            if(plays[i]>m[genres[i]][0].second){
                swap(m[genres[i]][0],m[genres[i]][1]);
            }
        }else if(m[genres[i]].size()>1){
            if(m[genres[i]][1].second<plays[i]){
                m[genres[i]].push_back(make_pair(i,plays[i]));
                swap(m[genres[i]][1],m[genres[i]][m[genres[i]].size()-1]);
                if(m[genres[i]][0].second<plays[i]){
                    swap(m[genres[i]][0],m[genres[i]][1]);
                }
            }
        }else{
            m[genres[i]].push_back(make_pair(i,plays[i]));
        }
    }
    vector<pair<string,int>> V(mm.begin(),mm.end());
    sort(V.begin(),V.end(),[](pair<string,int> p1, pair<string,int> p2){return p1.second>p2.second;});
    for(pair<string,int> p : V){
        if(m[p.first].size()==1){
            answer.push_back(m[p.first][0].first);
        }else{
            answer.push_back(m[p.first][0].first);
            answer.push_back(m[p.first][1].first);
        }
    }
    return answer;
}