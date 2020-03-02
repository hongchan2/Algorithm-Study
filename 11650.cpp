#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int num;
    cin >> num;
    vector<pair<int, int> > v;

    while(num--){
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }

    sort(v.begin(), v.end());

    for(pair<int, int> p : v){
        cout << p.first << " " << p.second << '\n';
    }

    return 0;
}