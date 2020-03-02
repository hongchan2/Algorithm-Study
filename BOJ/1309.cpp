#include <iostream>

#define endl '\n';

using namespace std;

int dp[3][100001] = { 0, };

int main(void){
    int n; 
    cin >> n;

    dp[0][1] = dp[1][1] = dp[2][1] = 1;
    for(int i = 2; i <= n; i++){
        dp[0][i] = (dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1]) % 9901;
        dp[1][i] = (dp[0][i - 1] + dp[2][i - 1]) % 9901;
        dp[2][i] = (dp[0][i - 1] + dp[1][i - 1]) % 9901;
    }

    cout  << (dp[0][n] + dp[1][n] + dp[2][n]) % 9901 << endl;

    return 0;
}
