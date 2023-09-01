#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int** W = new int* [n];
    bool* V = new bool[n];
    int* length = new int[wires.size()];
    for (int i = 0; i < n; i++) {
        W[i] = new int[n];
        V[i] = false;
    }
    for (int i = 0; i < n; i++) {
        W[i][i] = 1;
    }
    for (int i = 0; i < wires.size(); i++) {
        W[wires[i][0] - 1][wires[i][1] - 1] = 1;
        W[wires[i][1] - 1][wires[i][0] - 1] = 1;
        length[i] = 0;
    }

    stack<int> dfs;
    dfs.push(0);
    V[0] = true;
    for(int i = 0; i<wires.size(); i++){
        W[wires[i][0] - 1][wires[i][1] - 1] = 0;
        W[wires[i][1] - 1][wires[i][0] - 1] = 0;
        dfs.push(0);
        while (!dfs.empty()) {
            int now = dfs.top(); dfs.pop();
            length[i]++;
            for (int j =0; j< n; j++) {
                if (W[now][j] == 1 && !V[j]) {
                    dfs.push(j);
                    V[j] = true;
                }
            }
        }
        W[wires[i][0] - 1][wires[i][1] - 1] = 1;
        W[wires[i][1] - 1][wires[i][0] - 1] = 1;
        for(int k = 0; k<n; k++){
            V[k] = false;
        }
        length[i]--;
        
    }
    for(int i = 0; i< wires.size(); i++){
        cout<< length[i]<<" ";
        length[i] = n - 2*length[i];
        if(length[i]<0) length[i]*=-1;
    }
    for(int i = 0; i<wires.size()-1; i++){
        for(int j = i; j<wires.size();j++){
            if(length[i] > length[j]){
                int tmp = length[j];
                length[j] = length[i];
                length[i] = tmp;
            }
        }
    }
    

    return length[0];
}
