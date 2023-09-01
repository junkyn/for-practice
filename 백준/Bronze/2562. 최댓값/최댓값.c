#include <stdio.h>
int main() {
    int array[9];
    scanf("%d", &array[0]);
    int max = array[0];
    int count = 0;
    for (int i = 1; i < 9; i++) {
        scanf("%d", &array[i]);
        if (max < array[i]) {
            max = array[i];
            count = i;
        }
    }
    printf("%d\n%d", max, count+1);
    return 0;
}