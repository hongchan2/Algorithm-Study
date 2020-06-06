/*
    처음에는 반대로 시뮬레이션을 하면 될 줄 알았으나,
    큐가 존재하므로 순서대로 처리하면 되었음

    단순 실수했던 목록
    1. 비어있는지 체크하는 함수에서 실수로 모두 return true 를 했음
    2. B큐에 넣을 때, A가 비어졌을 때로 체크하지 않음 (있으면 계속 큐에 넣었음)

    시뮬레이션은 단순 출력으로 디버그가 쉬움!
    각 iteration마다 출력을 잘 찍어보기!
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, k, a, b;
// time, customer_num
pair<int, int> aStatus[21];
int bStatus[21];
int aTime[21];
int bTime[21];
int customerTime[1001];

queue<int> aQueue;
// customer_num, aIndex
queue<pair<int, int> > bQueue;

bool isEmptyA() {
	for (int i = 0; i < n; i++) {
		if (aStatus[i].first == 0) return true;
	}

	return false;
}

bool isEmptyB() {
	for (int i = 0; i < m; i++) {
		if (bStatus[i] == 0) return true;
	}
	
	return false;
}

void putA(int customerNum) {
	for (int i = 0; i < n; i++) {
		if (aStatus[i].first != 0) continue;

		aStatus[i].first = aTime[i];
		aStatus[i].second = customerNum;
		return;
	}
}

int putB() {
	for (int i = 0; i < m; i++) {
		if (bStatus[i] != 0) continue;

		bStatus[i] = bTime[i];
		return i + 1;
	}
}

void clearArray() {
	for (int i = 0; i < n; i++) {
		aStatus[i] = make_pair(0, 0);
	}
	for (int i = 0; i < m; i++) {
		bStatus[i] = 0;
	}
	while (!aQueue.empty()) aQueue.pop();
	while (!bQueue.empty()) bQueue.pop();
}

bool isEmptyAllSpace() {
	for (int i = 0; i < n; i++) {
		if (aStatus[i].first != 0) return false;
	}

	for (int i = 0; i < m; i++) {
		if (bStatus[i] != 0) return false;
	}

	return true;
}

void debug() {
	for (int i = 0; i < n; i++) {
		cout << aStatus[i].first << "/" << aStatus[i].second << " ";
	}
	cout << endl;

	for (int i = 0; i < m; i++) {
		cout << bStatus[i] << " ";
	}
	cout << endl;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		clearArray();
		
		cin >> n >> m >> k >> a >> b;
		for (int i = 0; i < n; i++) {
			cin >> aTime[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> bTime[i];
		}
		for (int i = 0; i < k; i++) {
			cin >> customerTime[i];
		}

		int answer = 0;
		int time = 0;
		int costomerIndex = 0;
		while (true) {
			if ((costomerIndex >= k) && aQueue.empty() && bQueue.empty() && isEmptyAllSpace()) break;

			while ((costomerIndex < k) && (customerTime[costomerIndex] == time)) {
				aQueue.push(costomerIndex + 1);
				costomerIndex++;
			}

			// 접수 창구
			vector<pair<int, int> > vec;
			for (int i = 0; i < n; i++) {
				if (aStatus[i].first == 0) continue;

				aStatus[i].first--;
				if (aStatus[i].first == 0) vec.push_back(make_pair(i + 1, aStatus[i].second));
			}

			int vecSize = vec.size();
			if (vecSize > 0) {
				sort(vec.begin(), vec.end());
				for (int i = 0; i < vecSize; i++) {
					bQueue.push(make_pair(vec[i].second, vec[i].first));
				}
			}

			while (isEmptyA()) {
				if (aQueue.empty()) break;

				int customerNum = aQueue.front(); aQueue.pop();

				putA(customerNum);
			}

			// 수리 창구
			for (int i = 0; i < m; i++) {
				if (bStatus[i] != 0) bStatus[i]--;
			}

			while (isEmptyB()) {
				if (bQueue.empty()) break;
				
				pair<int, int> p = bQueue.front(); bQueue.pop();
				int customerNum = p.first;
				int customerIndex = p.second;

				int putIndex = putB();
				if (customerIndex == a && putIndex == b) answer += customerNum;
			}

			//cout << endl;
			//cout << "TIME : " << time << endl;
			//debug();
			
			time++;
		}

		if (answer == 0) answer = -1;
		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}