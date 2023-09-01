#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

char** MAP;
bool** visited;
vector<int> solution(vector<string> maps) {
    int M = maps.size();
    int N = maps[0].size();
    MAP = new char*[M];
    visited = new bool* [M];
    vector<int> answer;
    for (int i = 0; i < M; i++) {
        MAP[i] = new char[N];
        visited[i] = new bool[N];
    }
    for (int i = 0; i < M; i++) {
        char* ch = new char[N];
        maps[i].copy(ch, N);
        for (int j = 0; j < N; j++) {
            MAP[i][j] = ch[j];
            visited[i][j] = (ch[j] == 'X') ? true : false;
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << MAP[i][j] << " ";
        }
        cout << endl;
    }
    int food=0;
    stack<pair<int, int>> point;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                point.push(make_pair(i, j));
                visited[i][j] = true;
                while (!point.empty()) {
                
                    pair<int, int> p = point.top();
                    point.pop();
                    food += MAP[p.first][p.second] - '0';
                    if (p.first - 1 >= 0 && !visited[p.first - 1][p.second]) {
                        point.push(make_pair(p.first-1,p.second));
                        visited[p.first - 1][p.second] = true;
                    }
                    if (p.first + 1 < M && !visited[p.first + 1][p.second]) {
                        point.push(make_pair(p.first + 1, p.second));
                        visited[p.first + 1][p.second] = true;
                    }
                    if (p.second - 1 >= 0 && !visited[p.first][p.second - 1]) {
                        point.push(make_pair(p.first, p.second - 1));
                        visited[p.first][p.second-1] = true;
                    }
                    if (p.second + 1 < N && !visited[p.first][p.second + 1]) {
                        point.push(make_pair(p.first, p.second + 1));
                        visited[p.first][p.second + 1] = true;
                    }
                }
                answer.push_back(food);
                food = 0;
            }
        }
    }
    if (answer.empty()) {
        answer.push_back(-1);
    }
    else {
        for (int i = 0; i < answer.size() - 1; i++) {
            for (int j = i; j < answer.size(); j++) {
                if (answer[i] > answer[j]) {
                    int tmp = answer[i];
                    answer[i] = answer[j];
                    answer[j] = tmp;
                }
            }
        }
    }
    return answer;
}