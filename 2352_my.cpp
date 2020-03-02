#include <iostream>
#include <algorithm>

using namespace std;
#define endl '\n'

int dp[40001] = { 0, };
int connect[40001] = { 0, };
bool check[40001] = { false, };

int main(void){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> connect[i];
    
    for(int i = 1; i <= n; i++){
        // max(connect, disconnect)
        int nextPort = connect[i];
        if(nextPort < i){
            dp[i] = dp[i - 1] + 1;
            for(int k = i - 1; k >= nextPort; k--){
                if(check[k] && connect[k] > nextPort){ 
                    dp[i]--;
                    break;
                }
            }
        }
        else{
            dp[i] = dp[i - 1] + 1;
            for(int j = i + 1; j <= nextPort; j++){
                if(connect[j] < nextPort)
                    dp[i]--;
            }
        }
        cout << i << " ) " << dp[i] << ", " << dp[i - 1] << endl;
        dp[i] = max(dp[i], dp[i - 1]);

        if(dp[i] > dp[i - 1])
            check[i] = true;
    }
    for(int i = 1; i <= n; i++)
        cout << check[i] << " ";
    cout << endl;

    cout << dp[n] << endl;
    return 0;
}