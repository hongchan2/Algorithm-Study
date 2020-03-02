#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;
#define endl '\n'
#define TEST cout << "TEST" << endl;

int check[100001] = { 0, };
int edge[100001] = { 0, };
int answer = 0;

void dfs(vector<int>& visit, int depth){
    if(check[visit[depth]]){
        for(int i = 0; i < depth; i++){
            if(visit[i] == visit[depth]){
                answer += depth - i;
                break;
            }
        }
        return;
    }
    check[visit[depth]]++;

    visit.push_back(edge[visit[depth]]);
    dfs(visit, depth + 1);
}

int main(void){
    int T;
    cin >> T;
    while(T--){        
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            scanf("%d", &edge[i]);
        }

        vector<int> visit;
        for(int i = 1; i <= n; i++){
            visit.push_back(i);
            dfs(visit, 0);
            visit.clear();
        }

        cout << n - answer << endl;

        answer = 0;
        memset(edge, 0, sizeof(edge));
        memset(check, 0, sizeof(check));
    }

    return 0;
}