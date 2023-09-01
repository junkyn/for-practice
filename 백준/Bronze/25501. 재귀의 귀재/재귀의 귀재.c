#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int recursion(const char* s, int l, int r,int* count) {
    *count = *count + 1;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1,count);
}

int isPalindrome(const char* s,int* count) {
    return recursion(s, 0, strlen(s) - 1,count);
}

int main() {
    int* count;
    int pt = 0;
    count = &pt;
    int n = 0;
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n*2);
    for (int i = 0; i < n; i++) {
        char* s = (char*)malloc(sizeof(char)*100);
        scanf("%s", s);
        arr[2*i] = isPalindrome(s, count);
        int temp = pt;
        arr[2 * i + 1] = temp;
        *count = 0;
    }
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", arr[2 * i], arr[2 * i + 1]);
    }
}