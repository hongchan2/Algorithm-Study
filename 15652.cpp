#include <cstdio>

using namespace std;
#define endl '\n'

int n, m;
int selected[8] = { 0, };

void dfs(int depth, int next){
    if(depth == m){
        for(int i = 0; i < m; i++){
            printf("%d ", selected[i]);
        }
        printf("\n");
        return;
    }

    for(int i = next; i <= n; i++){
        selected[depth] = i;
        dfs(depth + 1, i);
    }
}


int main(void){
    scanf("%d %d", &n, &m);
    dfs(0, 1);

    return 0;
}