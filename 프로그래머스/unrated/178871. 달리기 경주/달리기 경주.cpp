#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<string,int> M;
    for(int i = 0; i<players.size(); i++){
        M.insert(pair<string,int>(players[i],i));
    }
    for(string s : callings){
        int n = M.find(s)->second;
        swap(players[n],players[n-1]);
        M.find(s)->second = n-1;
        M.find(players[n])->second = n;
    }
    return players;
}