#include<vector>
#include <queue>
using namespace std;


int solution(vector<vector<int> > maps)
{
    //bool V[100][100];
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int m = maps.size();
    int n = maps[0].size();
    bool** V = new bool*[m];
    for(int i = 0; i<m; i++){
        V[i] = new bool[n];
        for(int j = 0; j<n; j++){
            V[i][j] = false;
        }
    }
    queue<pair<int,int>> bfs;
    V[0][0] = true;
    bfs.push(make_pair(0,0));
    int count = 0;
    while(!bfs.empty()){
        pair<int,int> r = bfs.front();bfs.pop();
        for(int i = 0; i <4; i++){
            int x = r.first+dx[i]; int y = r.second + dy[i];
            if(x== m-1 && y == n-1){
                return maps[r.first][r.second]+1;
            }
            if(x<0 || y<0 || V[x][y] || x>=m || y>=n || maps[x][y] == 0) continue;
            V[x][y] = true;
            maps[x][y] = maps[r.first][r.second]+1;
            bfs.push(make_pair(x,y));
        }
    }
    return -1;
}