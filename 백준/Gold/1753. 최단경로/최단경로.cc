#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class T{
public:
        int a,b,w;
        T(int a,int b,int w){
            this->a =a; this->b = b; this->w = w;
        }
};
struct cmp{
    bool operator()(T t1, T t2){
        return t1.w >t2.w;
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    int f;
    cin>>f;
    vector<vector<pair<int,int>>> E(n);
    priority_queue<T,vector<T>, cmp> PQ;
    for(int i = 0; i<m; i++){
        int a, b, w;
        cin>>a>>b>>w;
        E[a-1].emplace_back(make_pair(b,w));
    }
    vector<int> V(n,1000000);
    V[f-1] = 0;
    for(int i = 0; i < E[f-1].size(); i++){
        V[E[f-1][i].first-1] = E[f-1][i].second;
        PQ.push(T(f,E[f-1][i].first,E[f-1][i].second));
    }
    while(!PQ.empty()){
        T t = PQ.top();
        PQ.pop();
        if(V[t.b-1] < t.w) continue;
        V[t.b-1] = t.w;
        for(pair<int,int> edge : E[t.b-1]){
            if(t.w+edge.second < V[edge.first-1])
                PQ.push(T(t.b,edge.first,edge.second+t.w));
        }

    }
    for(int i = 0; i<n; i++){
        if(V[i] == 1000000) cout<<"INF"<<"\n";
        else cout<<V[i]<<"\n";
    }
    return 0;
}
