#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxX=0;int maxY=0;
    for(int i = 0; i<sizes.size(); i++){
        if(sizes[i][0] > sizes[i][1]) swap(sizes[i][0],sizes[i][1]);
        maxX = max(maxX, sizes[i][0]);
        maxY = max(maxY, sizes[i][1]);
    }
    return maxX * maxY;
}