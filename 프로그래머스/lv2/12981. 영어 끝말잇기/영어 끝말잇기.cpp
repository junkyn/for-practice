#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> game;
    string lastWord;
    for (int i = 0; i < words.size(); i++) {
        if (lastWord.empty()) {
            lastWord = words[i]; game.insert(words[i]);
        }
        else if (words[i].front() == lastWord.back()) {
            game.insert(words[i]);
            lastWord = words[i];
        }
        else {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            break;
        }
        if ((i+1) != game.size()) {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            break;
        }
    }
    if (answer.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}