#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define endl '\n'
int n, m;
int map[9][9] = { 0, };
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int total = 0;
vector<vector<pair<int, int> > > selected;
void dfs(int depth, int index, vector<pair<int, int> >& v) {
	if (depth == 3) {
		selected.push_back(v);
		return;
	}

	for (int i = index; i <= total; i++) {
		//check index
		int row = i / m; row++;
		int col = i % m;
		if (col == 0) {
			row--;
			col = m;
		}
		
		if (map[row][col] == 0) {
			v.push_back(make_pair(row, col));
			dfs(depth + 1, i + 1, v);
			v.pop_back();
		}
	}
}

int main(void) {
	vector<pair<int, int> > virus;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];

			if (map[i][j] == 2)
				virus.push_back(make_pair(i, j));
		}
	}

	vector<pair<int, int>> v;
	total = n * m;
	dfs(0, 1, v);

	/*for (auto v : selected) {
		for (auto n : v)
			cout << n.first << " " << n.second << " / " << " ";

		cout << endl;
	}*/
	
	int nextMap[9][9];
	int answer = -1;
	for (auto v : selected) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) 
				nextMap[i][j] = map[i][j];
		
		for (auto p : v)
			nextMap[p.first][p.second] = 1;

		
		queue<pair<int, int> > q;
		for (auto v : virus) {
			q.push(make_pair(v.first, v.second));
		}
		while (!q.empty()) {
			auto p = q.front(); q.pop();
			int cy = p.first;
			int cx = p.second;

			for (int i = 0; i < 4; i++) {
				int ny = cy + dy[i];
				int nx = cx + dx[i];

				if (ny >= 1 && ny <= n && nx >= 1 && nx <= m) {
					if (nextMap[ny][nx] == 0) {
						
						nextMap[ny][nx] = 2;
						q.push(make_pair(ny, nx));
					}
				}
			}
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (nextMap[i][j] == 0)
					cnt++;
			}
		}
		answer = max(answer, cnt);
	}

	cout << answer << endl;
	return 0;
}