/*
    내가 수행한 방식
    1. n명중에 n/2명을 선택해 한 팀을 먼저 꾸리기 (조합 nCn/2)
    2. 먼저 꾸린 팀에 없으면 다른 팀에 넣기
    3. 각 팀의 능력치 계산
    4. 최솟 값 저장

    1번과 2번 과정이 생각보다 복잡했는데, 찾아보고 괜찮았던 방식은 다음과 같다
    1) 재귀 (스타트팀, 링크팀에 속하는 두 가지로 분기 O(2^n)) 
    2) 순열 (0과 1을 반절씩 섞어서 순열(next_permutation) 돌리면서 0-스타트팀, 1-링크팀)
    3) 비트마스킹 (순열과 유사하나, 내가 아직 비트 마스킹을 모름. 공부 필요!)
*/

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int map[21][21] = { 0, };
int startTeam[11] = { 0, };
int linkTeam[11] = { 0, };

int minValue = 987654321;
void calc(){
    // TODO : 각 팀 계산하여 최솟 값 저장
    int linkIndex = 0;
    for(int i = 1; i <= n; i++){
        bool find = false;
        for(int j = 0; j < n / 2; j++){
            if(startTeam[j] == i){
                find = true;
                break;
            }
        }

        if(!find){
            linkTeam[linkIndex] = i;
            linkIndex++;
        }
    }

    int startSum = 0;
    int linkSum = 0;
    for(int i = 0; i < n / 2; i++){
        for(int j = i + 1; j < n / 2; j++){
            startSum += map[startTeam[i]][startTeam[j]];
            startSum += map[startTeam[j]][startTeam[i]];

            linkSum += map[linkTeam[i]][linkTeam[j]];
            linkSum += map[linkTeam[j]][linkTeam[i]];
        }
    }

    minValue = min(minValue, abs(startSum - linkSum));
}

void comb(int depth, int next){
    if(depth == (n/2)){
        calc();
        return;
    }

    for(int i = next; i <= n; i++){
        startTeam[depth] = i;
        comb(depth + 1, i + 1);
        // startTeam[depth] = 0;
    }
}

int main(void){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> map[i][j];
        }
    }

    comb(0, 1);

    cout << minValue;
    return 0;
}