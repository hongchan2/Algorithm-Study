#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl '\n'

vector<int> v;

int main(void){
    int n, next;
    cin >> n;

    v.push_back(-1);
    for(int i = 0; i < n; i++){
        cin >> next;
        if(v.back() < next){
            v.push_back(next);
        }
        else{
            auto iter = lower_bound(v.begin(), v.end(), next);
            *iter = next;
        }
    }
    // for(auto n : v)
    //     cout << n << " ";
    // cout << endl;

    cout << v.size() - 1 << endl;
    return 0;
}