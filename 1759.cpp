#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl '\n'
int l, c;
vector<char> v;
vector<char> selected;

bool check(){
    int mo = 0;
    int za = 0;
    for(int i = 0; i < l; i++){
        if(selected[i] == 'a' || selected[i] == 'e' || selected[i] == 'i'
        || selected[i] == 'o' || selected[i] == 'u')
            mo++;
        else
            za++;
    }

    if(mo >= 1 && za >= 2)
        return true;
    else
        return false;
}

void combination(int depth, int index){
    if(depth == l){
        //print
        if(check()){
            for(int i = 0; i < l; i++)
                cout << selected[i];
            cout << endl;
        }
        return;
    }

    for(int i = index; i < c; i++){
        selected.push_back(v[i]);
        combination(depth + 1, i + 1);
        selected.pop_back();
    }
}

int main(void){
    cin >> l >> c;
    for(int i = 0; i < c; i++){
        char c1;
        cin >> c1;
        v.push_back(c1);
    }
    sort(v.begin(), v.end());

    combination(0, 0);

    return 0;
}