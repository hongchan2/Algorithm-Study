#include <iostream>
#include <vector>

using namespace std;
#define endl '\n'

int n, r;
vector<int> v;
bool check[9] = { 0, };

void dfs(int depth){
    if(depth == r){
        for(auto n : v)
            cout << n << " ";
        cout << endl;
        return;
    }

    for(int i = 1; i <= n; i++){
        if(!check[i]){
            check[i] = true;
            v.push_back(i);
            dfs(depth + 1);
            v.pop_back();
            check[i] = false;
        }
    }
}

int main(void){
    cin >> n >> r;
    dfs(0);
    return 0;
}