#include <iostream>
#include <algorithm>

#define endl '\n';

using namespace std;

int n;
int r[1001] = { 0, };
int g[1001] = { 0, };
int b[1001] = { 0, };
int dp[3][1001] = { 0, };

int main(void){
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> r[i] >> g[i] >> b[i];

    for(int i = 1; i <= n; i++){
        dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + r[i];
        dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + g[i];
        dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + b[i];
    }

    cout << min(dp[0][n], min(dp[1][n], dp[2][n])) << endl;
    return 0;
}