#include <iostream>

#define endl "\n"

using namespace std;

int dp[1001] = { 0, };

int main(void){
    int n;
    cin >> n;

    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    cout << dp[n] % 10007 << endl;

    return 0;
}