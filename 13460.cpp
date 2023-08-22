#include <iostream>
#include <stack>
using namespace std;

class R;
class B;
bool isCango(int dir);
R* r;
B* b;
char** board;
int m, n;
int Count=0;


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
					return 0;
				}
			}break;
		case 1:
			for (int i = x - 1; i >= 0; i--) {
				if (board[i][y] == 'O')
					return -1;
				else if (board[i][y] != '.') {
					board[x][y] = '.';
					this->x = i + 1;
					board[x][y] = 'B';

					return 0;
				}
			}break;
		case 2:
			for (int i = y - 1; i >= 0; i--) {
				if (board[x][i] == 'O')
					return -1;
				else if (board[x][i] != '.') {
					board[x][y] = '.';
					this->y = i + 1;
					board[x][y] = 'B';
					return 0;
				}
			}break;
		case 3:
			for (int i = x + 1; i <= m; i++) {
				if (board[i][y] == 'O')
					return -1;
				else if (board[i][y] != '.') {
					board[x][y] = '.';
					this->x = i - 1;
					board[x][y] = 'B';
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
				if (board[x][i] == 'O') {
					board[x][y] = '.';
					return ++Count;
				}
				else if (board[x][i] != '.') {
					Count++;
					board[x][y] = '.';
					this->y = i - 1;
					board[x][y] = 'R';
					if (board[x][y - 1] == 'B') {
						board[x][y - 2] = '#';
					}
					else
						board[x][y - 1] = '#';
					return 0;
				}
			}break;
		case 1:
			for (int i = x-1; i >= 0; i--) {
				if (board[i][y] == 'O') {
					board[x][y] = '.';
					return ++Count;
				}
				else if (board[i][y] != '.') {
					Count++;
					board[x][y] = '.';
					this->x = i + 1;
					board[x][y] = 'R';
					if (board[x + 1][y] == 'B') {
						board[x + 2][y] = '#';
					}
					else
						board[x + 1][y] = '#';
					return 0;
				}
			}break;
		case 2:
			for (int i = y-1; i >= 0; i--) {
				if (board[x][i] == 'O') {
					board[x][y] = '.';
					return ++Count;
				}
				else if (board[x][i] != '.') {
					Count++;
					board[x][y] = '.';
					this->y = i + 1;
					board[x][y] = 'R';
					if (board[x][y + 1] == 'B') {
						board[x][y + 2] = '#';
					}
					else
						board[x][y + 1] = '#';
					return 0;
				}
			}break;
		case 3:
			for (int i = x+1; i <= m; i++) {
				if (board[i][y] == 'O') {
					board[x][y] = '.';
					return ++Count;
				}
				else if (board[i][y] != '.') {
					Count++;
					board[x][y] = '.';
					this->x = i - 1;
					board[x][y] = 'R';
					if (board[x-1][y] == 'B') {
						board[x-2][y] = '#';
					}
					board[x - 1][y] = '#';
					return 0;
				}
			}
		}
	}
	int FindDir() {
		int dir= -1;
		if (y + 1 <= n && board[x][y + 1] != '#' && isCango(0)) {dir = 0; }
		else if (x - 1 >= 0 && board[x - 1][y] != '#' && isCango(1)) { dir = 1; }
		else if (y-1 >= 0 && board[x][y-1] != '#' && isCango(2)) { dir = 2; }
		else if (x+1 <= m && board[x + 1][y] != '#' && isCango(3)) { dir = 3; }
		if (dir == this->lastDir) dir = -1;
		return dir;
	} 
};
bool isCango(int dir) {
	bool isNext = false;
	switch (dir) {
	case 0: if (board[r->x][r->y + 1] == 'B') isNext = true; break;
	case 1: if (board[r->x - 1][r->y] == 'B') isNext = true; break;
	case 2: if (board[r->x][r->y - 1] == 'B') isNext = true; break;
	case 3: if (board[r->x + 1][r->y] == 'B') isNext = true; break;
	}
	if (isNext) {
		if (!b->isFrontWall(dir))
			return true;
		else {
			return false;
		}
	}
	else
		return true;
}
class Points {
public:
	int rx, ry, bx, by, lDir, count;
	Points(int a, int b, int c, int d, int e, int count) {
		rx = a; ry = b; bx = c; by = d; lDir = e; this->count = count;
	}
};

stack <Points*> pointStack;
Points* GetPoint(){
	Points* p = new Points(r->x, r->y, b->x, b->y, r->lastDir, Count);
	
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
			cout << -1;
			return 0;
		}
		Points* point = pointStack.top();
		board[r->x][r->y] = '#';
		board[b->x][b->y] = '#';
		r->x = point->rx; r->y = point->ry; b->x = point->bx; b->y = point->by, r->lastDir = point->lDir; Count = point->count;
		board[r->x][r->y] = 'R';
		board[b->x][b->y] = 'B';
		int dir;
		if ((dir = r->FindDir()) == -1) {
			pointStack.pop();
		}
		else {
			int res;
			if((res = Operate(dir)) == 0)
				pointStack.push(GetPoint());
			else {
				if (res > 10) { cout << -1; return 0; }
				cout << res;
				return 0;
			}

		}
		
	}


}
// 0 오른 1 위 2 왼 3 아래