#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    for(int i =1; i<=r2; i++){
        answer+=floor(sqrt(pow(r2,2)-pow(i,2)))-ceil(sqrt(((pow(r1,2)-pow(i,2)) < 0) ? 0 : (pow(r1,2)-pow(i,2))))+1;
    }
    return 4*answer;
}