#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

#define endl '\n'

int board[201][201] = { 0, };
bool check[201][201][31] = { false, };
int horse_dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int horse_dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int normal_dy[4] = {-1, 0, 1, 0};
int normal_dx[4] = {0, 1, 0, -1};

int main(void){
    int k, h, w;
    cin >> k >> w >> h;
    // (1,1) ~ (h,w)
    for(int i = 1; i <= h; i++)
        for(int j = 1; j <= w; j++)
            cin >> board[i][j];

    // h, w, k 
    queue<tuple<int, int, int> > q;
    q.push(make_tuple(1, 1, k));
    check[1][1][k] = true;
    int answer = 0;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            tuple<int, int, int> t = q.front(); q.pop();
            int ch = get<0>(t);
            int cw = get<1>(t);
            int ck = get<2>(t);

            // cout << answer << "| " << ch << ", " << cw << " / " << ck << endl;
            if(ch == h && cw == w){
                cout << answer << endl;
                return 0;
            }

            int nh, nw, nk;
            // horse
            if(ck != 0){
                nk = ck  - 1;
                for(int i = 0; i < 8; i++){
                    nh = ch + horse_dy[i];
                    nw = cw + horse_dx[i];

                    if(nh >= 1 && nh <= h && nw >= 1 && nw <= w){
                        if(board[nh][nw] == 0 && !check[nh][nw][nk]){
                            check[nh][nw][nk] = true;
                            q.push(make_tuple(nh, nw, nk));
                        }
                    }   
                }
            }

            // normal
            for(int i = 0; i < 4; i++){
                nk = ck;
                nh = ch + normal_dy[i];
                nw = cw + normal_dx[i];

                if(nh >= 1 && nh <= h && nw >= 1 && nw <= w){
                    if(board[nh][nw] == 0 && !check[nh][nw][nk]){
                        check[nh][nw][nk] = true;
                        q.push(make_tuple(nh, nw, nk));
                    }
                }   
            }
        }
        answer++;
    }
    cout << -1 << endl;

    return 0;
}