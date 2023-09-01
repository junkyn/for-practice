#include<iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
public:   
    vector<Node*> linkedNode;
    int n;
    Node(int n) {
        this->n = n;
    }
    void Link(Node* node) {
        if (Search(node)) return;
        linkedNode.push_back(node);
    }
    bool Search(Node* node) {
        for (int i = 0; i < linkedNode.size(); i++) {
            if (linkedNode[i]->n == node->n || node->n == this->n) {
                return true;
            }
        }
        return false;
    }
    int FarNode() {
        int firstSize = linkedNode.size();
        int index = firstSize;
        int count = 0;
        vector<int> far;
        for (int i = 0; i < linkedNode.size(); i++) {
            if (i == index) {
                far.push_back(count);
                index = linkedNode.size();
                count = 0;
            }
            for (int j = 0; j < linkedNode[i]->linkedNode.size(); j++) {
                if (Search(linkedNode[i]->linkedNode[j])) {
                    continue;
                }
                else {
                    linkedNode.push_back(linkedNode[i]->linkedNode[j]);
                    count++;
                }
            }
        }
        return far.back();
    }

};
vector<Node*> nodes;
Node* createNode(int n) {
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i]->n == n) {
            return nodes[i];
        }
    }
    Node* node = new Node(n);
    nodes.push_back(node);
    return node;
}
int solution(int n, vector<vector<int>> edge) {
    for (int i = 0; i < edge.size(); i++) {
        Node* a; Node* b;
        a = createNode(edge[i][0]);
        b = createNode(edge[i][1]);
        a->Link(b); b->Link(a);
    }
    Node* oneN = new Node(0);
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i]->n == 1) {
            oneN = nodes[i];
        }
    }
    return oneN->FarNode();
}
