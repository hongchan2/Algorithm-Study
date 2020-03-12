#include <iostream>
#include <algorithm>

using namespace std;

#define endl '\n'

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int test_case;
	int T = 10;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int board[1001] = { 0, };
        int n;
        int sum = 0;
        cin >> n;

        // 1 ~ n
        for(int i = 1; i <= n; i++){
            cin >> board[i];
        }

        for(int i = 3; i <= n - 1; i++){
            int curFloor = board[i];
            int maxFloor = max(max(board[i - 2], board[i - 1]), max(board[i + 1], board[i + 2]));
            if(curFloor > maxFloor)
                sum += curFloor - maxFloor;
        }
        cout << "#" << test_case << " " << sum << endl;
	}
	return 0;
}