/*
    1. 0을 곱하는 경우 고려하지 못했음
    2. 디버깅 할 때 continue에 걸려서 무한루프인지 인지x
        -> 앞으로 반복문 맨 앞줄에 cout하기!
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, k;
bool check[100001] = { false, };
int direction[2] = { -1, 1 };

int main(void){
    cin >> n >> k;

    queue<int> q;
    check[n] = true;
    q.push(n);
    int answer = 0;
    while(!q.empty()){
        int qSize = q.size();
        while(qSize--){
            vector<int> v;
            int cur = q.front(); q.pop();
            v.push_back(cur);

            if(cur != 0){
                for(int i = cur * 2; i <= 100000; i *= 2){
                    if(check[i]) continue;

                    check[i] = true;
                    v.push_back(i);
                }
            }

            for(int curVec : v){    
                if(curVec == k){
                    cout << answer;
                    return 0;
                }

                for(int i = 0; i < 2; i++){
                    int next = curVec + direction[i];

                    if(next >= 0 && next <= 100000 && !check[next]){
                        check[next] = true;
                        q.push(next);
                    }
                }
            }
        }
        answer++;
    }

    return 0;
}