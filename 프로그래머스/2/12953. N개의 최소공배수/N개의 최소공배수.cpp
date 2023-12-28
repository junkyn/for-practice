#include <string>
#include <vector>

using namespace std;
int gcd(int a,int b){
    while(b!=0){
        int r = a%b;
        a=b;
        b=r;
    }
    return a;
}
long merge(vector<int> arr){
    if(arr.size()==1) return arr[0];
    if(arr.size()==2){
        return arr[0]*arr[1]/gcd(arr[0],arr[1]);
    }
    vector<int> a(arr.begin(),arr.begin()+arr.size()/2);
    vector<int> b(arr.begin()+arr.size()/2,arr.end());
    long n1 = merge(a);
    long n2 = merge(b);
    return n1*n2/gcd(n1,n2);
}
int solution(vector<int> arr) {
    
    return merge(arr);
}

