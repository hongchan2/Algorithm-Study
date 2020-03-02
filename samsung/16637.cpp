#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
#define TEST cout << "TEST" << endl;
#define PLUS 0
#define MINUS 1
#define MUL 2
int n;
string s;
vector<int> selected;
string temp = "";
vector<pair<int, int> > parResult;
int answer = -987654321;

void calcPar() {
	int vecIndex = 0;
	for (int i = 0; i < s.size(); i++) {
		if (!selected.empty() && selected[vecIndex] == i) {
			int o1 = s[i] - '0';
			int o2 = s[i + 2] - '0';
			char oper = s[i + 1];
			int result = 0;

			switch (oper) {
			case '+':
				result = o1 + o2;
				break;
			case '-':
				result = o1 - o2;
				break;
			case '*':
				result = o1 * o2;
				break;
			}
			parResult.push_back(make_pair(i, result));

			vecIndex++;
			i += 2;
		}
	}

	vecIndex = 0;
	int leftOper = 0;
	bool left = false;
	int curOper = 0;
	for (int i = 0; i < s.size(); i++) {
		if (!parResult.empty() && parResult[vecIndex].first == i) {
			int temp = parResult[vecIndex].second;
			if (!left) {
				left = true;
				leftOper = temp;
			}
			else {
				switch (curOper) {
				case PLUS:
					leftOper += temp;
					break;
				case MINUS:
					leftOper -= temp;
					break;
				case MUL:
					leftOper *= temp;
					break;
				}
			}
			//cout << leftOper << endl;
			vecIndex++;
			i += 2;
		}
		else {
			if (!left) {
				left = true;
				leftOper = s[i] - '0';
			}
			else if (s[i] == '-')
				curOper = MINUS;
			else if (s[i] == '+')
				curOper = PLUS;
			else if (s[i] == '*')
				curOper = MUL;
			else {
				switch (curOper) {
				case PLUS:
					leftOper += s[i] - '0';
					break;
				case MINUS:
					leftOper -= s[i] - '0';
					break;
				case MUL:
					leftOper *= s[i] - '0';
					break;
				}
			}
		}
		// cout << leftOper << endl;
	}
	answer = max(answer, leftOper);
	// cout << "answer : " << answer << endl;
	parResult.clear();
}

void dfs(int depth, int parSize, int index) {
	if (depth == parSize) {
		// end
		// cout << "parSize : " << parSize << endl << "loc    ";
		// for (auto n : selected)
		// 	cout << n << " ";
		// cout << endl;
		calcPar();
		return;
	}

	for (int i = index; i < s.size() - 2; i += 2) {
		selected.push_back(i);
		dfs(depth + 1, parSize, i + 4);
		selected.pop_back();
	}
}

int main(void) {
	cin >> n >> s;

	int totalParSize = 0;
	for (int i = 0; i < s.size() - 2; i += 4)
		totalParSize++;
	
	for (int i = 1; i <= totalParSize; i++) {
		dfs(0, i, 0);
	}

    selected.clear();
    calcPar();

	cout << answer << endl;

	return 0;
}