#include <iostream>

using namespace std;

int* stack;
int i = 0;
int j = 0;
int N;

void push() {
	int n;
	cin >> n;

	stack[j] = n;
	j = (j + 1) % N;
}

bool isEmpty() {
	return i == j;
}

void top() {
	if (isEmpty()) {
		cout << -1 << "\n";
		return;
	}
	int idx = j - 1;
	if (idx < 0) {
		idx = N - 1;
	}
	cout << stack[idx] << "\n";
}



void pop() {
	if (isEmpty()) {
		cout << -1 << "\n";
		return;
	}
	j--;
	if (j < 0) {
		j = N - 1;
	}
	cout << stack[j] << "\n";
	stack[j] = 0;

}


void empty() {
	if (isEmpty()) {
		cout << 1 << "\n";
	}
	else {
		cout << 0 << "\n";
	}
}

void size() {
	int size = j - i;
	if (i > j) {
		size = N + size;
	}

	cout << size << "\n";
}

int main() {
	cin >> N;
	stack = new int[N];

	for (int i = 0; i < N; i++) {
		stack[i] = 0;
	}

	for (int i = 0; i < N; i++) {
		string cmd;
		cin >> cmd;
		if (cmd.compare("push") == 0) {
			push();
		}
		if (cmd.compare("pop") == 0) {
			pop();
		}
		if (cmd.compare("size") == 0) {
			size();
		}
		if (cmd.compare("empty") == 0) {
			empty();
		}
		if (cmd.compare("top") == 0) {
			top();
		}
	}
}