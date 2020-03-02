#include <iostream>
#include <vector>

using namespace std;
#define endl '\n'

int n, r;
vector<int> v;

void dfs(int depth, int next){
    if(depth == r){
        for(auto n : v)
            cout << n << " ";
        cout << endl;
        return;
    }

    for(int i = next; i <= n; i++){
        v.push_back(i);
        dfs(depth + 1, i + 1);
        v.pop_back();
    }
}

int main(void){
    cin >> n >> r;
    dfs(0, 1);
    return 0;
}