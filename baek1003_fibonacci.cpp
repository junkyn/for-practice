#include <iostream>
using namespace std;
/* 백준 1003번
https://www.acmicpc.net/problem/1003
 
 단순히 0과 1이 나올때 증가시켜 출력하니 시간초과가 뜸
 -> 메모이제이션 구글링

 피보나치 수열에서 0과 1이 나오는 횟수 또한 피보나치 수열을 이루는걸 찾아
 n이 0과 1일때의 값을 미리 입력해주고, 횟수를 구할 때 마다 list에 저장을 해준다.
 그리고 n-1, n-2의 순서의 값이 이미 찾아놨던 순서라면 재귀를 사용하지 않고 
 바로 값을 가져와 시간을 절약한다.
*/
int** list;
bool* check;
int* fibonacci(int n) {
    if (n < 2) {
        return list[n];
    }
    else {
        int* arr = new int[2];
        int* arr1, * arr2;
        arr1 = new int[2];
        arr2 = new int[2];
        if (check[n - 1])
            arr1 = list[n - 1];
        else
            arr1 = fibonacci(n - 1);
        if (check[n - 2])
            arr2 = list[n - 2];
        else
            arr2 = fibonacci(n - 2);
        arr[0] = arr1[0] + arr2[0];
        arr[1] = arr1[1] + arr2[1];
        list[n] = arr;
        check[n] = true;
        return list[n];
    }
}
int main() {
    int count,num;
    cin >> count;
    list = new int*[41];
    check = new bool[41];
    for (int i = 0; i < 41; i++) {
        list[i] = new int[2];
        check[i] = false;
        list[i][0] = 0;
        list[i][1] = 0;
    }
    list[0][0] = 1;
    list[0][1] = 0;
    list[1][0] = 0;
    list[1][1] = 1;
    check[0] = true;
    check[1] = true;
    int* arr = new int[2];
    for (int i = 0; i < count; i++) {
        cin >> num;
        arr = fibonacci(num);
        cout << arr[0] << " " << arr[1] << endl;
    }

}