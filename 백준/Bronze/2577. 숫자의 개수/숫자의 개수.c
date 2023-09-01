#include <stdio.h>
int main() {
    int a, b, c, value,rest;
    int array[10]={0,};
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    value = a * b * c;
    while ((double)value/10 != 0) {
        rest = value % 10;
        value = value / 10;
        for (int j = 0; j < 10; j++) {
            if (j == rest)
                array[j]++;
        }

    }
    for(int k =0; k<10;k++)
        printf("%d\n", array[k]);
    return 0;
}