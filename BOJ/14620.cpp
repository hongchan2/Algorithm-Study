/*
    두 가지 잘 못 생각한 점으로 시간이 조금 소요되었음.
    1. check_possible 범위 지정
    2. index 지정
    -> 그냥 0 ~ n*n 전부를 대상으로 확인하며, 범위 벗어나면 continue 해주도록 함

    조합을 구할 때, index 지정이 아닌 for문을 2번 중첩해서 구해도 됨! - 주석처리 (틀린 것)
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int n;
int board[11][11] = { 0, };
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
vector<pair<int, int> > selected;
int min_value = 987654321;

bool check_possible(int cy, int cx){
    for(auto pair : selected){
        int target_y = pair.first;
        int target_x = pair.second;

        if(abs(cy - target_y) <= 1 && abs(cx - target_x) <= 1) return false;
        if(abs(cy - target_y) == 2 && cx == target_x) return false;
        if(abs(cx - target_x) == 2 && cy == target_y) return false;
    }
    return true;
}

int calculate(){
    int sum = 0;

    for(auto pair : selected){
        int cy = pair.first;
        int cx = pair.second;

        sum += board[cy][cx];
        for(int i = 0; i < 4; i++){
            sum += board[cy + dy[i]][cx + dx[i]];
        }
    }
    return sum;
}

void comb(int depth, int next){
    if(depth == 3){
        int num = calculate();
        min_value = min(min_value, num);
        return;
    }

    for(int i = next; i < n * n; i++){
        int y = (i / n);
        int x = (i % n);
        if(y == 0 || y == n - 1) continue;
        if(x == 0 || x == n - 1) continue;
        if(!check_possible(y, x)) continue;

        selected.push_back(make_pair(y, x));
        comb(depth + 1, i + 1);
        selected.pop_back();
    }
}

// void comb(int depth, int next_y, int next_x){
//     if(depth == 3){
//         int num = calculate();
//         min_value = min(min_value, num);
//         return;
//     }

//     for(int y = next_y; y < n - 1; y++){
//         for(int x = next_x; x < n - 1; x++){
//             if(!check_possible(y, x)) continue;

//             selected.push_back(make_pair(y, x));
//             if(x == n - 2) comb(depth + 1, y + 1, 1);
//             else comb(depth + 1, y, x + 1);
//             selected.pop_back();
//         }
//     }
// }

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    comb(0, 0);
    cout << min_value;
    return 0;
}