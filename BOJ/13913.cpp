/*
    풀이 1 : DFS
    cnt[] 배열을 모두 살펴보면서, 처음 지점으로 되돌아가는 재귀호출 수행
*/

#include <iostream>
#include <queue>

using namespace std;

int n, k;
int cnt[100001] = { 0, };
int direction[2] = { -1, 1 };

bool flag = false;
void dfs(int depth, vector<int>& vec){
    if(flag) return;

    int cur = vec.back();

    if(depth == 1){
        for(int i = vec.size() - 1; i >= 0; i--){
            cout << vec[i] << " ";
        }
        flag = true;
        return;
    }

    for(int i = 0; i < 3; i++){
        int next;
        if(i == 2){
            if(cur % 2 != 0) continue;
            
            next = cur / 2;
        } 
        else{
            next = cur + direction[i];
        }

        if(next >= 0 && next <= 100000 && cnt[next] == depth - 1){
            vec.push_back(next);
            dfs(depth - 1, vec);
            vec.pop_back();
        }
    }
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
            
            vector<int> vec;
            vec.push_back(cur);
            dfs(cnt[cur], vec);
            return 0;
        }

        for(int i = 0; i < 3; i++){
            int next;
            if(i == 2) next = 2 * cur;
            else next = cur + direction[i];

            if(next >= 0 && next <= 100000 && !cnt[next]){
                cnt[next] = cnt[cur] + 1;
                q.push(next);
            }
        }
    }

    return 0;
}