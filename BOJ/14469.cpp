#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int> > v;

int main(void){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int n1, n2;
        cin >> n1 >> n2;
        v.push_back(make_pair(n1, n2));
    }
    sort(v.begin(), v.end());

    int answer = 0;
    for(auto p : v){
        if(answer == 0){
            answer = v[0].first + v[0].second;
            continue;
        }

        if(answer <= p.first){
            answer = p.first + p.second;
        }
        else{
            answer += p.second;
        }
    }
    cout << answer;
    return 0;
}