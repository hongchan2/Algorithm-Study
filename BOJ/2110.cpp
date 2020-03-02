#include <iostream>
#include <algorithm>

using namespace std;
#define endl '\n'
#define TEST cout << "TEST" << endl

int house[200001] = { 0, };

int main(void){
    int n, c;
    cin >> n >> c;
    for(int i = 0; i < n; i++){
        cin >> house[i];
    }
    sort(house, house + n);
    
    int left = 1;
    int right = house[n - 1];
    int mid = 0;
    int answer = -987654321;
    while(left <= right){
        mid = (right + left) / 2;

        int selectedCnt = 1;
        int selected = house[0];
        for(int i = 0; i < n; i++){
            if(house[i] - selected >= mid){
                selected = house[i];
                selectedCnt++;
            }
        }

        if(selectedCnt < c){
            right = mid - 1;
        }
        else{
            // selectedCnt >= c
            answer = max(answer, mid);
            left = mid + 1;
        }
    }

    cout << answer;
    return 0;
}