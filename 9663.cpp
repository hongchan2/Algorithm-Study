#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
int cnt = 0;
int n;
vector<pair<int, int> > v;

void printVector(){
    for(auto p : v){
        cout << "(" << p.second << ", " << p.first << ")" << " ";
    }
    cout  <<endl;
}

bool promising(int x, int y){
    for(auto p : v){
        int n = p.first;
        int m = p.second;

        if(abs(n - x) == abs(m - y))    // 대각선 검사
            return false;

        if(n == x || m == y)            // 수평 수직 검사
            return false;
    }
    return true;
}

void dfs(int x, int y){
    if(y == n - 1){
        cnt++;
        //printVector();
        return;
    }

    for(int i = 0; i < n; i++){
        if(promising(i, y + 1)){
            // expand
            v.push_back(make_pair(i, y + 1));
            dfs(i, y + 1);
            v.pop_back();
        }
    }
}

int main(void){
    cin >> n;
    
    for(int i = 0; i < n; i++){
        v.push_back(make_pair(i, 0));
        dfs(i, 0);
        v.pop_back();
    }
    cout << cnt << endl;
    return 0;
}