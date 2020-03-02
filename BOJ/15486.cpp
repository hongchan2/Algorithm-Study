#include <iostream>
#include <algorithm>

using namespace std;

#define endl '\n'

int dp[1500001] = { 0, };
int t[1500001] = { 0, };
int p[1500001] = { 0, };

int main(void){
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> t[i] >> p[i];
    }

    if(t[n] == 1)
        dp[n] = p[n];
    else
        dp[n] = 0;

    int working;
    for(int i = n - 1; i > 0; i--){
        if(t[i] <= n - i + 1){
            // working possible
            working = dp[i + t[i]] + p[i];
        }
        else
            working = 0;

        dp[i] = max(working, dp[i + 1]);
    }

    // for(int i = n; i > 0; i--){
    //     cout << "dp[" << i << "] " << dp[i] << endl;
    // }

    cout << dp[1] << endl;

    return 0;
}