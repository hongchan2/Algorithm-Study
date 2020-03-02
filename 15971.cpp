#include <iostream>
#include <vector>

using namespace std;
#define endl '\n'

int n, r1, r2;
bool flag = false;
vector<int> path;
vector<pair<int, int> > edge[100001];
bool check[100001] = { false, };

void dfs(int node, vector<int>& v){
    if(check[node] || flag) return;
    
    check[node] = true;
    v.push_back(node);

    if(node == r2){
        flag = true;
        path = v;
        return;
    }

    //expand
    for(auto p : edge[node]){
        dfs(p.first, v);
    }
    v.pop_back();
}

bool checkAnswer(const int frontIndex, const int backIndex){
    // same position
    if(frontIndex == backIndex)
        return false;

    // find answer
    for(auto p : edge[path[frontIndex]])
        if(p.first == path[backIndex])
            return false;
    
    return true;
}

int main(void){
    cin >> n >> r1 >> r2;
    int n1, n2, distance;
    for(int i = 1; i < n; i++){
        cin >> n1 >> n2 >> distance;
        edge[n1].push_back(make_pair(n2, distance));
        edge[n2].push_back(make_pair(n1, distance));
    }

    vector<int> vec;
    dfs(r1, vec);

    int frontIndex = 0;
    int backIndex = path.size() - 1;
    int frontSum = 0;
    int backSum = 0;
    bool flag = checkAnswer(frontIndex, backIndex);
    while(flag){
        int frontDistance = 0;
        int backDistance = 0;
        for(auto p : edge[path[frontIndex]])
            if(p.first == path[frontIndex + 1])
                frontDistance = p.second;

        for(auto p : edge[path[backIndex]])
            if(p.first == path[backIndex - 1])
                backDistance = p.second;

        if(frontDistance < backDistance){
            // move front
            frontSum += frontDistance;
            frontIndex++;
        }
        else{
            // move back
            backSum += backDistance;
            backIndex--;
        }

        // check exist
        flag = checkAnswer(frontIndex, backIndex);
    }

    cout << frontSum + backSum << endl;
    return 0;
}