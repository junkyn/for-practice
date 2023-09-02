#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<vector<int>> vec;
    for(int i = 0; i< pow(4,emoticons.size()); i++){
        vector<int> v;
        for(int j = 0; j<emoticons.size(); j++){
            v.push_back(10* ((i / (int)pow(4,j)%4)+1));
        }
        vec.push_back(v);
    }
    vector<int> cust(users.size());
    pair<int,int> max = {0,0};
    for(int i = 0; i<vec.size(); i++){
        vector<int> price(vec[i].size());
        for(int j = 0; j<vec[i].size(); j++){
            price[j] = emoticons[j] * (100-vec[i][j]) / 100;
        }
        for(int j = 0; j<users.size(); j++){
            cust[j] = 0;
            for(int k = 0; k<price.size(); k++){
                if(users[j][0] <= vec[i][k]){
                    cust[j]+=price[k];
                }
            }
        }
        int count = 0;
        for(int j = 0; j<cust.size(); j++){
            if(cust[j]>=users[j][1]){
                count++;
                cust[j] = 0;
            }
        }
        int sum = 0;
        for(int j = 0; j<cust.size(); j++){
            sum+=cust[j];
        }
        if(count > max.first || (count==max.first && sum > max.second)){
            max = {count,sum};
        }
    }
    vector<int> answer = {max.first,max.second};
    return answer;
}