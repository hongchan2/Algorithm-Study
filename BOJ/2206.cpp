#include <iostream>
#include <queue>
#include <cstdio>
#include <tuple>

using namespace std;

#define endl '\n';
int board[1001][1001] = { 0, };
bool check[2][1001][1001] = { false, };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int main(void){
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%1d", &board[i][j]);
        }
    }

    if(n == 1 && m == 1 && board[1][1] == 0){
        cout << 1 << endl;
        return 0;
    }

    // y, x, bool
    queue<tuple<int, int, int> > q;
    check[0][1][1] = true;
    q.push(make_tuple(1, 1, 0));
    int answer = 1;
    int ny, nx, nbool;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            int cy = get<0>(q.front());
            int cx = get<1>(q.front());
            int cbool = get<2>(q.front());
            q.pop();

            for(int i = 0; i < 4; i++){
                ny = cy + dy[i];
                nx = cx + dx[i];
                nbool = cbool;

                // check range
                if(ny >= 1 && ny <= n && nx >= 1 && nx <= m){ 
                    // check bool
                    if(board[ny][nx] == 1){
                        if(nbool == 0)
                            nbool = 1;
                        else
                            continue;
                    }

                    // check visit
                    if(!check[nbool][ny][nx]){
                        //cout << "( " << ny << ", " << nx << " ) - " << nbool << endl;

                        if(ny == n && nx == m){
                            size = 0;
                            while(!q.empty())
                                q.pop();
                            break;
                        }

                        check[nbool][ny][nx] = true;
                        q.push(make_tuple(ny, nx, nbool));
                    }
                }
            } 
        }
        answer++;
    }

    if(ny == n && nx == m){
        cout << answer << endl;
    }
    else
        cout << -1 << endl;
    
    return 0;
}