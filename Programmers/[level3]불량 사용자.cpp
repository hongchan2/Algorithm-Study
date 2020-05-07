/*
    주요 실수
    1. set에서 값을 체크하는 로직이 잘못 됨 (차근차근 그려가면서 하고자 하는 것을 구현하기) - 막히면 그려가면서 어떻게 할 지 파악하기
    2. 설계의 중요성! 중간에 설계가 자주 바꾸면서 밑에 있는 단순 실수 발생해서 시간 많이 소요!
    ㄴ 단순히 어떻게 해야지가 아닌, 값 검사는 언제 어떤 식으로 해야지까지 생각해놓기

    단순 실수
    1. 인덱스 (i -> j 로 잘못 작성)
    2. 함수 호출 시 () 괄호 생략되어 항상 true가 되었음
*/

#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int m;
int n;
int answer;
vector<set<int> > vec;
vector<string> banned;
vector<string> user;
vector<int> selected;

// void debug(){
//     for(int i = 0; i < n; i++){
//         cout << user[selected[i]] << " ";
//     }
//     cout << endl;
// }

bool checkVec(){
    for(int i = 0; i < n; i++){
        if(user[selected[i]].size() != banned[i].size()) return false;

        int banned_size = banned[i].size();
        for(int j = 0; j < banned_size; j++){
            if(banned[i][j] == '*') continue;

            if(banned[i][j] != user[selected[i]][j]) return false;
        }
    }

    for(auto s : vec){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(s.find(selected[j]) != s.end()) cnt++;
        }
        if(cnt == n) return false;
    }
    return true;
}

bool check[8] = { false, };
void dfs(int depth){
    if(depth == n){
        if(!checkVec()) return;
        
        answer++;

        set<int> new_set;
        for(int num : selected) new_set.insert(num);
        vec.push_back(new_set);
        return;
    }

    for(int i = 0; i < m; i++){
        if(check[i]) continue;

        check[i] = true;
        selected.push_back(i);
        dfs(depth + 1);
        selected.pop_back();
        check[i] = false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    m = user_id.size(); n = banned_id.size();
    user = user_id; banned = banned_id;
    answer = 0;

    dfs(0);

    return answer;
}