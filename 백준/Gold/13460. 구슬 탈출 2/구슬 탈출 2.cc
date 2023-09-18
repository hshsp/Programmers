#include <iostream>
#include <string>

using namespace std;

int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} }; //상하좌우
int row, col;
int minRes = 100;

typedef struct _pos {
	int row;
	int col;
}pos;
void PrintMap(char map[][10], int res, string history) {
	cout << "*********************" << endl;
	cout << res << endl;
	cout << "history : " << history << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
	cout << "*********************" << endl;
}

bool Bmove2R(pos B, pos R, int moveNum) {
	while (B.row < row - 1 && B.col < col - 1
		&& B.row > 0 && B.col > 0) {
		if (B.row == R.row && B.col == R.col) {
			return true;
		}
		B.row += dir[moveNum][0];
		B.col += dir[moveNum][1];
	}
	return false;
}

bool Rmove2B(pos B, pos R, int moveNum) {
	while (R.row < row && R.col < col
		&& R.row > 0 && R.col > 0) {
		if (R.row == B.row && R.col == B.col) {
			return true;
		}
		R.row += dir[moveNum][0];
		R.col += dir[moveNum][1];
	}
	return false;
}
void DFS(int moveNum, char oriMap[][10], int res, string history) {
	pos R, oriR;
	pos B, oriB;
	pos O;
	char map[10][10];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			map[i][j] = oriMap[i][j];
		}
	}

	if (res > 10) {
		return;
	}

	//위치 찾기
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] == 'R') {
				R.row = i;
				R.col = j;
			}
			else if (map[i][j] == 'B') {
				B.row = i;
				B.col = j;
			}
			else if (map[i][j] == 'O') {
				O.row = i;
				O.col = j;
			}
		}
	}
	oriR = R;
	oriB = B;

	bool RinO = false;
	bool BinO = false;
	//이동시키기
	//if (B.row + dir[moveNum][0] == R.row && B.col + dir[moveNum][1] == R.col) {
	if( Bmove2R ( B, R, moveNum ) ){
		//R 먼저 이동시키기
		map[R.row][R.col] = '.';
		while (map[R.row + dir[moveNum][0]][R.col + dir[moveNum][1]] == '.'
			|| map[R.row + dir[moveNum][0]][R.col + dir[moveNum][1]] == 'O') {
			R.row += dir[moveNum][0];
			R.col += dir[moveNum][1];
			if (map[R.row][R.col] == 'O') {
				break;
			}
		}
		if (map[R.row][R.col] == 'O') {
			//R이 O를 만나면 win
			/*
			if (minRes > res) {
				minRes = res;
			}
			return;
			*/
			RinO = true;
		}
		else {
			//continue
			map[R.row][R.col] = 'R';
		}

		map[B.row][B.col] = '.';
		while (map[B.row + dir[moveNum][0]][B.col + dir[moveNum][1]] == '.'
			|| map[B.row + dir[moveNum][0]][B.col + dir[moveNum][1]] == 'O') {
			B.row += dir[moveNum][0];
			B.col += dir[moveNum][1];
			if (map[B.row][B.col] == 'O') {
				break;
			}
		}
		if (map[B.row][B.col] == 'O') {
			//B가 O를 만나면 lose
			//return;
			BinO = true;
		}
		else {
			//continue
			map[B.row][B.col] = 'B';
		}
	}
	//else if (R.row + dir[moveNum][0] == B.row && R.col + dir[moveNum][1] == B.col) {
	if (Rmove2B(B, R, moveNum)) {
		//B 먼저 이동시키기
		map[B.row][B.col] = '.';
		while (map[B.row + dir[moveNum][0]][B.col + dir[moveNum][1]] == '.'
			|| map[B.row + dir[moveNum][0]][B.col + dir[moveNum][1]] == 'O') {
			B.row += dir[moveNum][0];
			B.col += dir[moveNum][1];
			if (map[B.row][B.col] == 'O') {
				break;
			}
		}
		if (map[B.row][B.col] == 'O') {
			//B가 O를 만나면 lose
			//return;
			BinO = true;
		}
		else {
			//continue
			map[B.row][B.col] = 'B';
		}


		map[R.row][R.col] = '.';
		while (map[R.row + dir[moveNum][0]][R.col + dir[moveNum][1]] == '.'
			|| map[R.row + dir[moveNum][0]][R.col + dir[moveNum][1]] == 'O') {
			R.row += dir[moveNum][0];
			R.col += dir[moveNum][1];
			if (map[R.row][R.col] == 'O') {
				break;
			}
		}
		if (map[R.row][R.col] == 'O') {
			//R이 O를 만나면 win
			/*
			if (minRes > res) {
				minRes = res;
			}
			return;
			*/
			RinO = true;
		}
		else {
			//continue
			map[R.row][R.col] = 'R';
		}
	}
	else {
		//상관 없음 그럼 그냥 위에 합쳐도 되나...?
		//B 먼저 이동시키기
		map[B.row][B.col] = '.';
		while (map[B.row + dir[moveNum][0]][B.col + dir[moveNum][1]] == '.'
			|| map[B.row + dir[moveNum][0]][B.col + dir[moveNum][1]] == 'O') {
			B.row += dir[moveNum][0];
			B.col += dir[moveNum][1];
			if (map[B.row][B.col] == 'O') {
				break;
			}
		}
		if (map[B.row][B.col] == 'O') {
			//B가 O를 만나면 lose
			//return;
			BinO = true;
		}
		else {
			//continue
			map[B.row][B.col] = 'B';
		}


		map[R.row][R.col] = '.';
		while (map[R.row + dir[moveNum][0]][R.col + dir[moveNum][1]] == '.'
			|| map[R.row + dir[moveNum][0]][R.col + dir[moveNum][1]] == 'O') {
			R.row += dir[moveNum][0];
			R.col += dir[moveNum][1];
			if (map[R.row][R.col] == 'O') {
				break;
			}
		}
		if (map[R.row][R.col] == 'O') {
			//R이 O를 만나면 win
			/*
			if (minRes > res) {
				minRes = res;
			}
			return;
			*/
			RinO = true;
		}
		else {
			//continue
			map[R.row][R.col] = 'R';
		}
	}

	if (RinO || BinO) {
		if (RinO && !BinO) {
			//R은 들어갔는데 B는 안 들어갔으면 win
			if (minRes > res) {
				minRes = res;
				//PrintMap(map, res, history+to_string(moveNum));
			}
		}
		return;
	}

	//R, B의 위치가 바뀌지 않았으면 이 방향으로는 더 안 가도 됨
	bool notThere = false;
	if (oriR.row == R.row && oriR.col == R.col
		&& oriB.row == B.row && oriB.col == B.col) {
		notThere = true;
	}

	for (int i = 0; i < 4; i++) {
		if (notThere && i == moveNum) {
			continue;
		}
		DFS(i, map, res + 1, history+to_string(moveNum));
	}
}

void test(char map[][10]) {
	map[0][0] = '.';
	return;
}

void test2() {
	pos A, B;
	A.row = 0;
	A.col = 0;
	B = A;
	cout << "바꾸기 전" << endl;
	cout << A.row << " " << A.col << endl;
	cout << B.row << " " << B.col << endl;

	A.row = 1;
	A.col = 5;
	cout << "바꾸기 후" << endl;
	cout << A.row << " " << A.col << endl;
	cout << B.row << " " << B.col << endl;

	// 결과 : 바꾸기 후에 B는 A를 따라 바뀌지 않음, 그대로 0 0
	// ==> 값을 복사함
}


int main() {
	char map[10][10];

	cin >> row >> col;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
		}
	}

	
	for (int i = 0; i < 4; i++) {
		DFS(i, map, 1, "");
	}

	//test2();

	/*
	test(map);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
	*/

	if (minRes == 100) {
		minRes = -1;
	}
	cout << minRes << endl;
}