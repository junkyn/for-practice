#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    pair<int,int> p = {0,0};
    vector<vector<char>> MAP;
    for(string v : park){
        vector<char> m(v.begin(),v.end());
        MAP.push_back(m);
    }
    bool isFind = false;
    for(int i = 0; i < MAP.size(); i++){
        if(isFind) break;
        for(int j = 0; j<MAP[i].size(); j++){
            if(MAP[i][j] == 'S'){
                p = {i,j}; isFind = true; break;
            }
        }
    }
    for(string s : routes){
        pair<int,int> lp = p;
        vector<char> c(s.begin(),s.end());
        for(int i = 0; i < c[2]-'0'; i++){
            if(c[0]=='E') p.second+=1;
            else if(c[0]=='W')p.second-=1;
            else if(c[0]=='S')p.first+=1;
            else if(c[0]=='N')p.first-=1;
            if(p.first >= MAP.size() || p.first < 0 || p.second>=MAP[0].size() || p.second<0 || MAP[p.first][p.second] == 'X'){
                p = lp; break;
            }
        }
    }
    vector<int> answer = {p.first,p.second};
    return answer;
}