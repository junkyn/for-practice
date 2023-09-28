#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(),targets.end(),[](vector<int> v1, vector<int> v2)->bool{return v1[1]>v2[1];});
    vector<pair<int,int>> V;
    for(vector v : targets){
        if(V.empty()) V.push_back(make_pair(v[0],v[1]));
        else{
            for(int i = 0; i<V.size(); i++){
                if(V[i].first >= v[1] || V[i].second<=v[0]){
                    if(i==V.size()-1) V.push_back(make_pair(v[0],v[1]));
                }
                else{
                    if(V[i].first < v[0]) V[i].first = v[0];
                    if(V[i].second > v[1]) V[i].second = v[1];
                    break;
                }
            }
        }
    }
    return V.size();
}