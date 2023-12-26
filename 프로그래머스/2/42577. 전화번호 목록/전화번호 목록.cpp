#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(),phone_book.end());
    for(int i = 0;i<phone_book.size()-1; i++){
        for(int j = i+1; j<phone_book.size(); j++){
            if(phone_book[i].size()>phone_book[j].size())break;
            unsigned long int s1, s2;
            if(phone_book[i].size()<8){
                s1 = stoi(phone_book[i]);
                s2 = stoi(phone_book[j].substr(0,phone_book[i].size()));         
            }
            else if(phone_book[i].size()>8){
                s1 = stoi(phone_book[i].substr(phone_book[i].size()-8,8));
                s2 = stoi(phone_book[j].substr(phone_book[i].size()-8,8));
            }
            if(s1<s2){
                break;
            }
            if(s1==s2){
                return false;
            }
        }
    }
    return true;
}