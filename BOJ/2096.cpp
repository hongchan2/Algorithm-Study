#include <iostream>
#include <algorithm>

using namespace std;

#define endl '\n'

int dp[100002][3] = { 0, };
//int map[100001][3] = { 0, };

int main(void){
    int n;
    cin >> n;
    for(int i = 2; i <= n + 1; i++){
        for(int j = 0; j < 3; j++){
            cin >> dp[i][j];
        }
    }

    int pre0;
    int pre1;
    int pre2;
    for(int i = 2; i <= n + 1; i++){
        // 현재 값 저장
        pre0 = dp[i][0];
        pre1 = dp[i][1];
        pre2 = dp[i][2];

        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + dp[i][0];
        dp[i][1] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2])) + dp[i][1];
        dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + dp[i][2];

        // i - 1 위치 복구
        dp[i - 1][0] = pre0;
        dp[i - 1][1] = pre1;
        dp[i - 1][2] = pre2;
    }
    cout << max(dp[n + 1][0], max(dp[n + 1][1], dp[n + 1][2])) << " ";

    for(int i = 1; i <= n; i++){
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + dp[i][0];
        dp[i][1] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + dp[i][1];
        dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + dp[i][2];
    }
    cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << endl;
    return 0;
}