#include <iostream>

using namespace std;
#define TEST cout << "TEST" << endl

int main(void){
    int t;
    cin >> t;
    while(t--){
        int score[100001] = { 0, };

        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            int n1, n2;
            cin >> n1 >> n2;
            score[n1] = n2;
        }

        int answer = 0;
        int smallest = 987654321;
        for(int i = 1; i <= n; i++){
            if(score[i] < smallest){
                answer++;
                smallest = score[i];
            }
        }
        cout << answer << endl;
    }
    return 0;
}