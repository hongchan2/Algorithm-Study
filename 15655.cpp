#include <iostream>
#include <algorithm>

using namespace std;
#define endl '\n'

int n, m;
int nums[8] = { 0, };
int selected[8] = { 0, };
bool check[8] = { false, };

void dfs(int depth, int next){
    if(depth == m){
        for(int i = 0; i < m; i++)
            cout << selected[i] << " ";
        cout << endl;
        return;
    }

    for(int i = next; i < n; i++){
        if(check[i]) continue;
        check[i] = true;
        selected[depth] = nums[i];
        dfs(depth + 1, i);
        check[i] = false;
    }
}

int main(void){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    
    sort(nums, nums + n);
    dfs(0, 0);

    return 0;
}