/*
    1. 미세먼지 확산하는 부분을 '동시에' 진행했어야 했는데,
    문제를 완벽히 이해하지 못하고 '차례대로' 확산을 진행하게 풀어서
    문제점을 파악하고 해결하는데 시간을 많이 소모함
    동시에 : 하나의 미세먼지 확산은 다른 미세먼지에 영향을 끼치지 않음!
    -> 문제의 예시를 꼼꼼히 보고 난 후 코딩을 하자!

    2. 인덱스를 잘 못 지정함
    구체적으로, row, col을 입력으로 받았는데, 배열의 인덱스는 0 ~ row - 1 임!!
    -> 입력 값을 배열의 인덱스로 사용할 때 꼼꼼히 확인하기!
*/
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int map[51][51] = { 0, };
int check[51][51] = { 0, };
int r, c, t;
pair<int, int> air = make_pair(-1, -1);
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void debug() {
	cout << endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

void spread() {
	queue<tuple<int, int, int> > q;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] < 5) continue;

			int spreadCnt = 0;
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];

				if (ny >= 0 && ny < r && nx >= 0 && nx < c) {
					if (map[ny][nx] == -1) continue;

					spreadCnt++;
					q.push(make_tuple(ny, nx, map[i][j] / 5));
				}
			}
			map[i][j] -= ((map[i][j] / 5) * spreadCnt);
		}
	}

	while (!q.empty()) {
		tuple<int, int, int> t = q.front(); q.pop();

		map[get<0>(t)][get<1>(t)] += get<2>(t);
	}
}

void wind(){
	// up
	int prev = map[air.first][1];
	map[air.first][1] = 0;
	for (int i = 2; i < c; i++) {
		int temp = map[air.first][i];
		map[air.first][i] = prev;
		prev = temp;
	}

	for (int i = air.first - 1; i >= 0; i--) {
		int temp = map[i][c - 1];
		map[i][c - 1] = prev;
		prev = temp;
	}

	for (int i = c - 2; i >= 0; i--) {
		int temp = map[0][i];
		map[0][i] = prev;
		prev = temp;
	}

	for (int i = 1; i < air.first; i++) {
		int temp = map[i][0];
		map[i][0] = prev;
		prev = temp;
	}

	// down
	prev = map[air.second][1];
	map[air.second][1] = 0;
	for (int i = 2; i < c; i++) {
		int temp = map[air.second][i];
		map[air.second][i] = prev;
		prev = temp;
	}

	for (int i = air.second + 1; i < r; i++) {
		int temp = map[i][c - 1];
		map[i][c - 1] = prev;
		prev = temp;
	}

	for (int i = c - 2; i >= 0; i--) {
		int temp = map[r - 1][i];
		map[r - 1][i] = prev;
		prev = temp;
	}

	for (int i = r - 2; i > air.second; i--) {
		int temp = map[i][0];
		map[i][0] = prev;
		prev = temp;
	}
}

int main(void) {
	cin >> r >> c >> t;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			
			if (map[i][j] == -1 && air.first == -1) {
				air.first = i;
			}
		}
	}
	air.second = air.first + 1;

	while (t--) {
		spread();
		//debug();
		wind();
		//debug();
	}

	int answer = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			answer += map[i][j];
		}
	}
	cout << answer + 2;

	return 0;
}