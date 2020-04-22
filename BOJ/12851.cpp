/*
    쉽게 생각했다가 오래 걸렸던 문제

    1. 기존 BFS 처럼 풀었음 (중복된 것은 queue에 삽입 안함)
    2. 0 <= N <= 100,000 범위를 잘 못봄 (< 로 보아서 100000을 포함하지 않음)
    
    기존 BFS는 최단 거리만 알면 됨!
    이 문제는 (1)최단 거리 + (2)최단 거리로 가는 방법의 수를 알아야 함
    따라서, 기존 BFS는 중복된 곳을 방문하지 않지만(큐에 넣지 않지만)
    이 문제는 중복된 것을 방문해야 함(큐에 넣어야 함)
    -> pop할 때 방문처리
*/

#include <iostream>
#include <queue>

using namespace std;
#define endl '\n';

int n, k;
bool check[100001] = { false, };

int main(void){
    cin >> n >> k;

    queue<int> q;
    q.push(n);
    int answerTime = 0;
    int answerCnt = 0;
    while(!q.empty()){
        int qSize = q.size();
        while(qSize--){
            int cur = q.front(); q.pop();
            check[cur] = true;

            if(cur == k) answerCnt++;

            if(cur - 1 >= 0 && !check[cur - 1]) q.push(cur - 1);

            if(cur + 1 <= 100000 && !check[cur + 1]) q.push(cur + 1);
            
            if(cur * 2 <= 100000 && !check[cur * 2]) q.push(cur * 2);
        }

        if(answerCnt) break;

        answerTime++;
    }
    cout << answerTime << endl;
    cout << answerCnt;
    return 0;
}