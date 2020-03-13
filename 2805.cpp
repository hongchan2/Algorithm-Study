#include <iostream>
#include <algorithm>

using namespace std;
#define endl '\n'
#define TEST cout << "TEST" << endl;

int n, m;
int tree[1000001] = { 0, };

int main(void){
    cin >> n >> m;
    int maxValue = -987654321;
    for(int i = 0; i < n; i++){
        cin >> tree[i];
        maxValue = max(maxValue, tree[i]);
    }

    int left = 0;
    int right = maxValue - 1;
    int mid = 0;
    int answer = -987654321;
    while(left <= right){
        mid = (left + right) / 2;

        long long sum = 0;
        for(int i = 0; i < n; i++){
            int result = tree[i] - mid;
            if(result > 0)
                sum += result;
        }

        if(sum >= m){
            answer = max(answer, mid);
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    cout << answer;
    return 0;
}