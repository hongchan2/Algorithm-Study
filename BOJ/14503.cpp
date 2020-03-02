#include <iostream>

using namespace std;
#define endl '\n'
#define TEST cout << "TEST" << endl;

int map[51][51] = { 0, };
bool check[51][51] = { 0, };
int answer = 0;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int main(void){
    int n, m;
    cin >> n >> m;
    int r, c, d;
    cin >> r >> c >> d;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }
    
    bool find = true;
    while(true){
        if(find && !check[r][c]){ // 벽도 처리?
            // 1
            check[r][c] = true;
            answer++;
        }
        else{
            // c, d
            int nd = (d + 2) % 4;
            int nr = r + dr[nd];
            int nc = c + dc[nd];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                if(map[nr][nc]){
                    // d
                    break;
                }
                else{
                    // c
                    r = nr;
                    c = nc;
                    find = true;
                }
            }
            else{
                // d
                break;
            }
        }

        // cout << endl;
        // cout << "direction " << d << endl;
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         cout << check[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        int i;
        for(i = 0; i < 4; i++){
            // 2
            int nd = (d + 3) % 4;
            int nr = r + dr[nd];
            int nc = c + dc[nd];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                if(!map[nr][nc] && !check[nr][nc]){
                    // a
                    d = nd;
                    r = nr;
                    c = nc;
                    break;
                }
            }
            // b
            d = nd;
        }

        if(i == 4){
            find = false;
        }
    }
    
    cout << answer;
    return 0;
}