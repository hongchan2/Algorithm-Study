#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;
#define endl '\n'
int threeIndex[6][3] = {
    {0, 1, 2},
    {0, 2, 1},
    {1, 0, 2},
    {1, 2, 0},
    {2, 0, 1},
    {2, 1, 0}
};
int getSize(vector<int>& v){
    int returnValue = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] > 0)
            returnValue++;
        else
            v[i] = 0;
    }
    return returnValue;
}

int main(void){
    int n;
    vector<int> initSCV(3, 0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> initSCV[i];

    // scv(1, 2, 3) / size
    queue<pair<vector<int>, int> > q;
    bool check[61][61][61] = { false, };
    check[initSCV[0]][initSCV[1]][initSCV[2]] = true;
    q.push(make_pair(initSCV, n));
    int answer = 0;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            vector<int> curSCV = q.front().first;
            int curSize = q.front().second;
            q.pop();

            // cout << endl;
            // cout << curSize << endl;
            // cout << curSCV[0] << " " << curSCV[1] << " " << curSCV[2] << endl;

            if(curSize == 0){
                // end
                while(!q.empty())
                    q.pop();
                break;
            }

            for(int i = 0; i < 6; i++){
                vector<int> newSCV = curSCV;

                newSCV[threeIndex[i][0]] -= 9;
                newSCV[threeIndex[i][1]] -= 3;
                newSCV[threeIndex[i][2]] -= 1;

                int nextSize = getSize(newSCV);
                if(nextSize < 3)
                    sort(newSCV.begin(), newSCV.end(), greater<int>());
                
                if(!check[newSCV[0]][newSCV[1]][newSCV[2]]){
                    check[newSCV[0]][newSCV[1]][newSCV[2]] = true;
                    q.push(make_pair(newSCV, nextSize));
                }
            }
        }
        answer++;
    }

    cout << --answer << endl;
    return 0;
}