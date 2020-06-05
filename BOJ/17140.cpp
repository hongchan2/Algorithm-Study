#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

int r, c, k;
int rowCnt = 3;
int colCnt = 3;
int board[101][101] = { 0, };

void debug() {
	cout << endl;
	for (int i = 1; i <= rowCnt; i++) {
		for (int j = 1; j <= colCnt; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

int main(void) {
	cin >> r >> c >> k;

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> board[i][j];
		}
	}

	int answer = 0;
	while (true) {
		if (board[r][c] == k) {
			cout << answer;
			return 0;
		}

		if (answer > 100) {
			cout << -1;
			return 0;
		}

		// num, cnt
		map<int, int> m;
		// cnt, num
		vector<pair<int, int> > vec;
		if (rowCnt >= colCnt) {
			// R 연산
			int maxColCnt = -987654321;
			for (int i = 1; i <= rowCnt; i++) {
				for (int j = 1; j <= colCnt; j++) {
					if (!board[i][j]) continue;

					m[board[i][j]]++;
				}

				map<int, int>::iterator iter;
				for (iter = m.begin(); iter != m.end(); iter++) {
					vec.push_back(make_pair(iter->second, iter->first));
				}

				sort(vec.begin(), vec.end());
				int vecSize = vec.size();
				int boardIndex = 0;
				for (int j = 0; j < vecSize; j++) {
					if (boardIndex == 100) break;

					boardIndex++;
					board[i][boardIndex] = vec[j].second;
					boardIndex++;
					board[i][boardIndex] = vec[j].first;
				}

				for (int j = boardIndex + 1; j <= colCnt; j++) {
					board[i][j] = 0;
				}

				m.clear();
				vec.clear();
				maxColCnt = max(maxColCnt, boardIndex);
			}

			colCnt = maxColCnt;
		}
		else {
			// C 연산
			int maxRowCnt = -987654321;
			for (int i = 1; i <= colCnt; i++) {
				for (int j = 1; j <= rowCnt; j++) {
					if (!board[j][i]) continue;

					m[board[j][i]]++;
				}

				map<int, int>::iterator iter;
				for (iter = m.begin(); iter != m.end(); iter++) {
					vec.push_back(make_pair(iter->second, iter->first));
				}

				sort(vec.begin(), vec.end());
				int vecSize = vec.size();
				int boardIndex = 0;
				for (int j = 0; j < vecSize; j++) {
					if (boardIndex == 100) break;

					boardIndex++;
					board[boardIndex][i] = vec[j].second;
					boardIndex++;
					board[boardIndex][i] = vec[j].first;
				}

				for (int j = boardIndex + 1; j <= rowCnt; j++) {
					board[j][i] = 0;
				}

				m.clear();
				vec.clear();
				maxRowCnt = max(maxRowCnt, boardIndex);
			}

			rowCnt = maxRowCnt;
		}

		//debug();
		answer++;
	}

	return 0;
}