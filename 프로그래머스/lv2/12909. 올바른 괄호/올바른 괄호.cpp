#include <string>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

bool solution(string s)
{
    char* c = new char[s.size() + 1];
    stack<bool> isOpen;
    queue<char> str;
    s.copy(c, s.size()+1);
    for (int i = 0;; i++) {
        if (c[i] == NULL) break;
        str.push(c[i]);
    }
    while (!str.empty()) {
        char b = str.front();
        str.pop();
        if (b == '(') {
            isOpen.push(false);
        }
        else if (b == ')') {
            if (isOpen.empty()) return false;
            isOpen.top() = !isOpen.top();
            isOpen.pop();
        }
    }
    while (!isOpen.empty()) {
        if (!isOpen.top()) {
            return false;
        }
        isOpen.pop();
    }

    return true;
}