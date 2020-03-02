#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int num;
    vector<pair<int, int> > v;
    cin >> num;

    while(num--){
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(y, x)); // y, x
    }

    sort(v.begin(), v.end());

    for(pair<int, int> p : v){
        cout << p.second << " " << p.first << '\n';
    }

    return 0;
}