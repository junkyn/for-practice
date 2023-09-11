#include <algorithm>
#include <vector>
using namespace std;
vector<int> PreV;
vector<int> PostV;
class Node {
public:
    int n;
    Node* P=NULL;
    Node* L=NULL;
    Node* R=NULL;
    int x;
    Node(int x, int n) { this->x = x; this->n = n; }
};

void Pre(Node* n) {
    if (n == NULL) return;
    PreV.push_back(n->n);
    Pre(n->L);

    Pre(n->R);
}
void Post(Node* n){
    if(n==NULL) return;
    Post(n->L);
    Post(n->R);
    PostV.push_back(n->n);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    for (int i = 0; i < nodeinfo.size(); i++) {
        nodeinfo[i].push_back(i + 1);
    }
    sort(nodeinfo.begin(), nodeinfo.end(), [](vector<int> v1, vector<int> v2) -> bool { return v1[1] > v2[1]; });
    vector<vector<vector<int>>> V(nodeinfo[0][1]+1);
    int idx = 0;
    int top = nodeinfo[0][1];
    for (int i = 0; i < nodeinfo.size(); i++) {
        if (nodeinfo[i][1] == top) {
            V[idx].push_back(nodeinfo[i]);
        }
        else {
            top = nodeinfo[i][1];
            V[++idx].push_back(nodeinfo[i]);
        }
    }
    V.resize(idx + 1);
    vector<vector<Node*>> Nodes(V.size());
    for (int i = 0; i < Nodes.size(); i++) {
        sort(V[i].begin(), V[i].end(), [](vector<int> v1, vector<int> v2)-> bool {return v1[0] < v2[0]; });
        for (int j = 0; j < V[i].size(); j++) {
            Nodes[i].push_back(new Node(V[i][j][0], V[i][j][2]));
        }
    }
    Nodes[0][0]->P = NULL;
    for (int i = 1; i < Nodes.size(); i++) {
        for (int j = 0; j < Nodes[i].size(); j++) {
            Node* Root = Nodes[0][0];
            Node* Par;
            bool isLeft = true;
            for (int k = 0; k < i; k++) {
                Par = Root;
                if (Nodes[i][j]->x > Root->x) {

                    Root = Root->R;
                    isLeft = false;
                }
                else {
                    Root = Root->L;
                    isLeft = true;
                }
            }
            if (isLeft) { Par->L = Nodes[i][j]; Nodes[i][j]->P = Par; }
            else { Par->R = Nodes[i][j]; Nodes[i][j]->P = Par; }

        }
    }
    Node* Root = Nodes[0][0];
    Post(Root);
    Pre(Root);
    vector<vector<int>> answer = {PreV,PostV};
    return answer;
}