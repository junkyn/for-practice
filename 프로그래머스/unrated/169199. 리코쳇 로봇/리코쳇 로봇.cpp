#include <string>
#include <vector>
#include <queue>
using namespace std;
char B[100][100];
bool V[100][100];
int solution(vector<string> board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            B[i][j] = board[i].c_str()[j];
        }
    }
    vector<int> R(2);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            V[i][j] = false;
            if (B[i][j] == 'R') {
                R[0] = i; R[1] = j;
            }
        }
    }
    int xDir[4] = { 1,-1,0,0 };
    int yDir[4] = { 0,0,1,-1 };
    queue<pair<vector<int>, int>> bfs;
    int count = -1;
    bfs.push(make_pair(R, count));

    while (!bfs.empty()) {
        pair<vector<int>, int> p = bfs.front();
        bfs.pop();
        vector<int> nowR = p.first;
        V[nowR[0]][nowR[1]] = true;
        count = p.second;
        count++;
        for (int i = 0; i < 4; i++) {
            R = nowR;
            do {
                R = { R[0] + xDir[i], R[1] + yDir[i] };
                if (R[0] < 0 || R[0] >= board.size() || R[1] < 0 || R[1] >= board[0].size() || B[R[0]][R[1]] == 'D') {
                    R = { R[0] - xDir[i], R[1] - yDir[i] };
                    if (B[R[0]][R[1]] == 'G') return count+1;
                    if (V[R[0]][R[1]]) {
                        break;
                    }
                    else {
                        bfs.push(make_pair(R, count));
                        break;
                    }
                }

            } while (true);
        }
    }



    int answer = -1;
    return answer;
}
