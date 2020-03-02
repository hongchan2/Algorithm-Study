#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int num;
    long long sum = 0;
    vector<int> v;

    cin >> num;

    for(int i = 0; i < num; i++){
        int n;
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());
    
    for(int i = 0; i < num; i++){
        sum += abs(v[i] - (i+1));
    }
    cout << sum << '\n';
    return 0;
}
