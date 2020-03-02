#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'
bool check[100001] = { false, };
vector<int> edge[100001];
queue<int> answer;

void dfs(int x){
    if(check[x])
        return;
    
    check[x] = true;
    // cout << x << endl;
    for(int i = 0; i < edge[x].size(); i++){
        for(auto n : edge[x]){
            if(answer.front() == n && !check[n]){
                answer.pop();
                dfs(n);
            }
        }
    }
}

int main(void){
    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++){
        int n1, n2;
        cin >> n1 >> n2;
        edge[n1].push_back(n2);
        edge[n2].push_back(n1);
    }
    for(int i = 0; i < n; i++){
        int n1;
        cin >> n1;
        answer.push(n1);
    }

    if(answer.front() == 1)
        answer.pop();
    else{
        cout << 0 << endl;
        return 0;
    }        

    dfs(1);
    // cout << answer.size() << endl;
    if(!answer.empty())
        cout << 0 << endl;
    else
        cout << 1 << endl;

    return 0;
}