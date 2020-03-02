#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl '\n'
int curCard = 0;

void nextCard(vector<int>& v){
    vector<int>::iterator iter;
    iter = upper_bound(v.begin(), v.end(), curCard);
    if(iter != v.end()){
        curCard = *iter;
        v.erase(iter);
    }
    else
        curCard = 0;
}

int main(void){
    int n;
    vector<int> sang;
    vector<int> geun;

    cin >> n;
    for(int i = 0; i < n; i++){
        int n1;
        cin >> n1;
        sang.push_back(n1);
    }
    sort(sang.begin(), sang.end());
    int index = 0;
    for(int i = 1; i <= 2 * n; i++){
        if(sang[index] == i){
            index++;
            continue;
        }

        geun.push_back(i);
    }

    while(!sang.empty() && !geun.empty()){
        nextCard(sang);
        if(sang.empty())
            break;
        
        nextCard(geun);
    }

    int sangScore = geun.size();
    int geunScore = sang.size();
    cout << sangScore << endl << geunScore << endl;

    return 0;
}