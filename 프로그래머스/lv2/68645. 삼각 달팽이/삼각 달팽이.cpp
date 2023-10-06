#include <vector>
using namespace std;
vector<int> solution(int n) {
    vector<int> answer(n*(n+1)/2, -1);
    int d[3] = {1,1,-n};
    int k = 0;
    int p = 0;
    int f = 1;
    answer[0] = 1;
    for(int i = 2; i<=answer.size(); i++){
        if(p+d[k] >= answer.size() || p+d[k] < 0 || answer[p+d[k]]!=-1){
            k = (k==2) ? 0 : (k+1);
            d[0] = f; d[2] = -f;
            i--;
            continue;
        }
        p+=d[k];
        answer[p] = i;
        if(k==0) d[0]=++f;
        else if(k==2) d[2]=-(--f);
    }
    return answer;
}