#include <iostream>
using namespace std;

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