#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int k, int m, vector<int> score) {
    sort(score.begin(), score.end());
    int sum = 0;
    for (int i = 0; i < score.size()/m; i++) {
        sum += score[score.size()%m + i * m]*m;
        
    }
    return sum;
}