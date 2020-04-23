/*
    풀이 2 : 이전 경로 저장 후 재귀

    from 배열에 어디로 부터 왔는지에 대한 경로를 저장
    from 배열을 이용해서 재귀적으로 탐색 후 반대로 출력 (순서대로 출력하면 반대이므로)
*/

#include <iostream>
#include <queue>

using namespace std;

int n, k;
int cnt[100001] = { 0, };
int from[100001] = { 0, };
int direction[2] = { -1, 1 };

// from[k] -> from[n]
void dfs(int cur, int target){
    if(cur != target) dfs(from[cur], target);
    
    cout << cur << " ";
}

int main(void){
    cin >> n >> k;

    queue<int> q;
    q.push(n);
    cnt[n] = 1;
    while(!q.empty()){
        int cur = q.front(); q.pop();

        if(cur == k){
            cout << cnt[cur] - 1 << endl;
            dfs(cur, n);
            return 0;
        }

        for(int i = 0; i < 3; i++){
            int next;
            if(i == 2) next = 2 * cur;
            else next = cur + direction[i];

            if(next >= 0 && next <= 100000 && !cnt[next]){
                cnt[next] = cnt[cur] + 1;
                from[next] = cur;
                q.push(next);
            }
        }
    }

    return 0;
}