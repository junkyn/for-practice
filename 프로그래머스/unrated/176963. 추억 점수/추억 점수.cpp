#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    map<string,int> M;
    for(int i = 0; i<name.size(); i++){
        M.insert({name[i],yearning[i]});
    }
    vector<int> answer;
    for(vector v : photo){
        int sum = 0;
        for(string s : v){
            if(M.find(s) != M.end()){
                sum+=M[s];
            }
        }
        answer.push_back(sum);
    }
    return answer;
}