#include <iostream>
#include <algorithm>

using namespace std;
#define endl '\n'
#define TEST cout << "TEST" << endl;

long long lans[1000001] = { 0, };

int main(void){
    long long k, n;
    cin >> k >> n;
    for(int i = 0; i < k; i++){
        cin >> lans[i];
    }
    sort(lans, lans + k);

    long long left = 1;
    long long right = lans[k - 1];
    long long answer = -987654321;
    while(left <= right){
        long long mid = (left + right) / 2;
        // cout << mid << endl;
        // cout << left << " " << mid << " " << right << endl;
        long long sum = 0;
        for(int i = 0; i < k; i++){
            sum += lans[i] / mid;
        }

        if(sum < n){
            right = mid - 1;
        }
        else{
            // cout << "got : " << mid << endl;
            answer = max(answer, mid);
            left = mid + 1;
        }
    }

    cout << answer;
    return 0;
}