#include <iostream>
#include <vector>

using namespace std;
#define endl '\n'
#define TEST cout << "TEST" << endl;

int n;
vector<vector<int> > computers(3);
int check[201] = { 0, };
int answer = 1;

void dfs(int cur){    
    for(int i = 0; i < n; i++){
        if(computers[cur][i] && !check[i]){
            check[i] = answer;
            dfs(i);
        }
    }
}

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int n1;
            cin >> n1;
            computers[i].push_back(n1);
        }
    }

    for(int i = 0; i < n; i++){
        if(check[i]) continue;

        check[i] = answer;
        dfs(i);
        answer++;
    }
    
    cout << answer - 1;
    return 0;
}