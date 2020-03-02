#include <iostream>

using namespace std;
#define endl '\n'
#define TEST cout << "TEST" << endl;

long long dp[60001] = { 0, };

int main(void){
    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
    cout << dp[n] % 1000000007;
    return 0;
}