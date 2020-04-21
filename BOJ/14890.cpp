/*
    초기 설계를 꼼꼼히하고, 모든 경우의 수를 파악한 다음에 코딩하자!

    1.같은 곳에 경사로를 놓는 경우 생각하지 않음
    2.경로 체크를 함수화 할 생각하지 않고, 무작정 열을 기준으로 코딩을 시작함
    -> 그래도 2번을 해서 단위 테스트&디버깅이 수월했음!
*/
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;
#define endl '\n'
#define TEST cout << "TEST" << endl;

int n, l;
int map[101][101] = { 0, };
bool check[101] = { false, };

int checkRoute(const vector<int>& v){
    memset(check, false, sizeof(check));

    int prev = v[0];
    int j = 1;
    for(j = 1; j < n; j++){
        if(abs(prev - v[j]) > 1) break;

        bool possible = true;
        vector<int> subCheck;
        if(prev < v[j]){
            for(int k = 1; k <= l; k++){
                if(j - k < 0){
                    possible = false;
                    break;
                }

                if(check[j - k] || v[j - k] != prev){
                    possible = false;
                    break;
                }

                subCheck.push_back(j - k);
            }
        }
        else if(prev > v[j]){
            for(int k = 0; k < l; k++){
                if(j + k >= n){
                    possible = false;
                    break;
                }

                if(check[j + k] || v[j + k] != v[j]){
                    possible = false;
                    break;
                }

                subCheck.push_back(j + k);
            }
        }

        if(!possible) break;

        for(int n : subCheck) check[n] = true;
        
        prev = v[j];
    }

    return j == n;
}

int main(void){
    cin >> n >> l;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }

    int answer = 0;
    for(int i = 0; i < n; i++){
        vector<int> rowVec;
        vector<int> colVec;
        for(int j = 0; j < n; j++){
            rowVec.push_back(map[i][j]);
            colVec.push_back(map[j][i]);
        }
        if(checkRoute(rowVec)) answer++;
        if(checkRoute(colVec)) answer++;
    }

    cout << answer;
    return 0;
}