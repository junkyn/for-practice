#include <string>
#include <vector>
using namespace std;

vector<int> DP;
int solution(vector<vector<int>> triangle) {
    for(int i = 1; i<triangle.size(); i++){
        for(int j = 0; j<triangle[i].size(); j++){
            if(j == 0){
                triangle[i][j] += triangle[i-1][0];
            }
            else if(j == triangle[i].size()-1){
                triangle[i][j] += triangle[i-1][triangle[i-1].size()-1];
            }else{
                triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
    }


    for(int i = 1; i< triangle[triangle.size()-1].size(); i++){
        if(triangle[triangle.size()-1][0] < triangle[triangle.size()-1][i]){
            triangle[triangle.size()-1][0] = triangle[triangle.size()-1][i];
        }
    }
    int answer = triangle[triangle.size()-1][0];
    return answer;
}
