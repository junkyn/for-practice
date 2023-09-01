#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Hanoi(int n, int from, int to, int aux,int* pt) {
	*pt = *pt+1;
	if (n == 1)
		return;
	else {
		Hanoi(n - 1, from, aux, to, pt);
		Hanoi(n - 1, aux, to, from,pt);
	}
}
void Hanoip(int n, int from, int to, int aux) {
	if (n == 1) {
		printf("%d %d\n", from, to);
		return;
	}

	else {
		Hanoip(n - 1, from, aux, to);
		printf("%d %d\n", from, to);
		Hanoip(n - 1, aux, to, from);
	}
}
int main() {
	int count = 0;
	int* pt = &count;
	int n = 0;
	scanf("%d", &n);
	Hanoi(n,1,3,2,pt);
	printf("%d\n", count);
	Hanoip(n, 1, 3, 2);
}
