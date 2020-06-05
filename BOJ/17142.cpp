/*
    BFS 종료 조건을 잘 못 생각함
    다음은 시도한 순서
    1. BFS가 끝나면 검사 (로직 에러)
    2. BFS 중간중간에 검사 (TLE)
        -> 해당 좌표가 도달..이런 것은 매번 체크해야하지만,
            이 문제는 1초가 흐른 후 체크를 해도 되므로, 중간중간x
    3. BFS 끝난 후에 검사 (TLE)
        -> 시간 제한이 0.3초인데, 매번 n^2을 확인하는 것은 불가
    4. cnt 값을 BFS 동작하는 동안에 증가시켜서 검사
        -> O(1)만에 종료 확인이 가능함

    BFS 종료 조건을 사전에 잘 설계하기!!!!!!
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'

int n, m;
int board[51][51] = { 0, };
vector<pair<int, int> > virus;
vector<int> selected;
int answer = 987654321;
int emptyCnt = 0;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void debug(bool check[51][51]) {
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << check[i][j] << " ";
		}
		cout << endl;
	}
}

void simulation() {
	bool check[51][51] = { false, };

 	queue<pair<int, int> > q;
	for (int i = 0; i < m; i++) {
		int virusY = virus[selected[i]].first;
		int virusX = virus[selected[i]].second;

		q.push(make_pair(virusY, virusX));
		check[virusY][virusX] = true;
	}

	int time = 0;
	int curCnt = 0;
	while (!q.empty()) {
		if (time >= answer) return;

		// check logic
		/*bool isFinish = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!check[i][j] && !board[i][j]) {
					isFinish = false;
					i = n;
					break;
				}
			}
		}

		if (isFinish) {
			answer = min(answer, time);
			return;
		}*/
		if (curCnt == emptyCnt) {
			answer = min(answer, time);
			return;
		}
		
		int qSize = q.size();
		while (qSize--) {
			pair<int, int> p = q.front(); q.pop();
			int cy = p.first;
			int cx = p.second;

			for (int i = 0; i < 4; i++) {
				int ny = cy + dy[i];
				int nx = cx + dx[i];

				if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
					if (check[ny][nx]) continue;
					if (board[ny][nx] == 1) continue;

					if (!board[ny][nx]) curCnt++;
					check[ny][nx] = true;
					q.push(make_pair(ny, nx));
				}
			}
		}
		time++;
	}

	return;
}

void dfs(int depth, int index) {
	if (depth == m) {
		simulation();
		return;
	}

	int virusSize = virus.size();
	for (int i = index; i < virusSize; i++) {
		selected.push_back(i);
		dfs(depth + 1, i + 1);
		selected.pop_back();
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];

			if (board[i][j] == 2) virus.push_back(make_pair(i, j));
			if (!board[i][j]) emptyCnt++;
		}
	}

	dfs(0, 0);

	if (answer == 987654321) cout << -1;
	else cout << answer;
	
	return 0;
}