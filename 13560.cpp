#include <iostream>
#include <stack>
using namespace std;

class R;
class B;
R* r;
B* b;
char** board;
int m, n;
int Count=0;
void Print() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << " ";
		}cout << endl;
	}
}
class B {
public:
	int x = 0; int y = 0;
	B() {

	}
	B(int x, int y) {
		this->x = x; this->y = y;
	}
	int Operate(int dir) { // 정상 0, 구멍에 들어감 -1

		switch (dir) {
		case 0:
			for (int i = y + 1; i <= n; i++) {
				if (board[x][i] == 'O')
					return -1;
				else if (board[x][i] != '.') {
					board[x][y] = '.';
					this->y = i - 1;
					board[x][y] = 'B';
					board[x][y - 1] = '#';
					return 0;
				}
			}break;
		case 1:
			for (int i = x - 1; i >= 0; i--) {
				cout << board[i][y] << endl;
				if (board[i][y] == 'O')
					return -1;
				else if (board[i][y] != '.') {
					board[x][y] = '.';
					this->x = i + 1;
					board[x][y] = 'B';
					board[x + 1][y] = '#';

					return 0;
				}
			}break;
		case 2:
			for (int i = y - 1; i >= 0; i--) {
				if (board[x][i] == 'O')
					return -1;
				else if (board[x][i] != '.') {
					Count++;
					board[x][y] = '.';
					this->y = i + 1;
					board[x][y] = 'B';
					board[x][y + 1] = '#';
					return 0;
				}
			}break;
		case 3:
			for (int i = x + 1; i <= m; i++) {
				if (board[i][y] == 'O')
					return -1;
				else if (board[i][y] != '.') {
					Count++;
					board[x][y] = '.';
					this->x = i - 1;
					board[x][y] = 'B';
					board[x - 1][y] = '#';
					return 0;
				}
			}
		}
	}
	bool isFrontWall(int dir) {
		switch (dir) {
		case 0: return board[x][y + 1] == '#'; break;
		case 1: return board[x - 1][y] == '#'; break;
		case 2: return board[x][y - 1] == '#'; break;
		case 3: return board[x + 1][y] == '#'; break;

		}
	}
};

class R {
public:
	int x;
	int y;
	int lastDir = -2;
	R() {
		this->x = 0;
		this->y = 0;
	}
	R(int x, int y) {
		this->x = x;
		this->y = y;
	}
	bool isBlueOnDir(int dir) {
		switch (dir) {
		case 0:
			for (int i = y; i < n; i++) {
				if (board[x][i] == '#') break;
				if (board[x][i] == 'B') return true;
			}
			return false; break;
		case 1:
			for (int i = x; i > 0; i--) {
				if (board[i][y] == '#') break;
				if (board[i][y] == 'B') return true;
			}
			return false; break;
		case 2:
			for (int i = y; i > 0; i--) {
				if (board[x][i] == '#') break;
				if (board[x][i] == 'B') return true;
			}
			return false; break;
		case 3:
			for (int i = x; i < m; i++) {
				if (board[i][y] == '#') break;
				if (board[i][y] == 'B') return true;
			}
			return false; break;
		}
	}
	int Operate(int dir) { // 정상 0, 성공 Count
		lastDir = dir;
		switch (dir) {
		case 0:
			for (int i = y+1; i <= n; i++) {
				if (board[x][i] == 'O')
					return ++Count;
				else if (board[x][i] != '.') {
					Count++;
					board[x][y] = '.';
					this->y = i - 1;
					board[x][y] = 'R';
					return 0;
				}
			}break;
		case 1:
			for (int i = x-1; i >= 0; i--) {
				cout << board[i][y] << endl;
				if (board[i][y] == 'O')
					return ++Count;
				else if (board[i][y] != '.') {
					Count++;
					board[x][y] = '.';
					this->x = i + 1;
					board[x][y] = 'R';

					return 0;
				}
			}break;
		case 2:
			for (int i = y-1; i >= 0; i--) {
				if (board[x][i] == 'O')
					return ++Count;
				else if (board[x][i] != '.') {
					Count++;
					board[x][y] = '.';
					this->y = i + 1;
					board[x][y] = 'R';
					return 0;
				}
			}break;
		case 3:
			for (int i = x+1; i <= m; i++) {
				if (board[i][y] == 'O')
					return ++Count;
				else if (board[i][y] != '.') {
					Count++;
					board[x][y] = '.';
					this->x = i - 1;
					board[x][y] = 'R';
					return 0;
				}
			}
		}
	}
	int FindDir() {
		int dir= -1;
		cout << x << " , " << y << endl;
		if (y + 1 <= n && board[x][y + 1] != '#' && (isBlueOnDir) && !(b->isFrontWall(0))) {dir = 0; }
		else if (x - 1 >= 0 && board[x - 1][y] != '#' && !(b->isFrontWall(1))) { dir = 1; }
		else if (y-1 >= 0 && board[x][y-1] != '#' && !(b->isFrontWall(2))) { dir = 2; }
		else if (x+1 <= m && board[x + 1][y] != '#' && !(b->isFrontWall(3))) { dir = 3; }
		if (dir == this->lastDir) dir = -1;
		return dir;
	} 
};


class Points {
public:
	int rx, ry, bx, by, lDir;
	Points(int a, int b, int c, int d, int e) {
		rx = a; ry = b; bx = c; by = d; lDir = e;
	}
};

stack <Points*> pointStack;
Points* GetPoint(){
	Points* p = new Points(r->x, r->y, b->x, b->y, r->lastDir);
	
	return p;
}
int Operate(int dir) { // 정상 0
	if (r->isBlueOnDir(dir)) {
		if(b->Operate(dir) == -1) return -1;
		else {
			if (r->Operate(dir) != 0) return Count;
			return 0;
		}
	}
	else {
		int a = r->Operate(dir);
		if (b->Operate(dir) == -1) return -1;
		else {
			return a;
		}
		return 0;
	}
}
int main() {
	cin >> m >> n;
	board = new char* [m];
	for (int i = 0; i < m; i++) {
		board[i] = new char[n];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'R')
				r = new R(i, j);
			if (board[i][j] == 'B')
				b = new B(i, j);
		}
	}
	pointStack.push(GetPoint());
	while (true) {
		if (pointStack.empty()) {
			cout << 0;
			return 0;
		}
		Print();
		Points* point = pointStack.top();
		r->x = point->rx; r->y = point->ry; b->x = point->bx; b->y = point->by, r->lastDir = point->lDir;
		cout <<"이전경로 : "  << r->lastDir << endl;
		int dir;
		if ((dir = r->FindDir()) == -1) {
			cout <<"지금 경로 : "<< dir << endl;
			pointStack.pop();
		}
		else {
			int res;
			if((res = Operate(dir)) == 0)
				pointStack.push(GetPoint());
			else {
				cout << res;
				return res;
			}

		}
		
	}


}
// 0 오른 1 위 2 왼 3 아래