#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
#define MINUS 0
#define PLUS 1
vector<char> number;
deque<pair<char, int> > q;

void addNumber(){
    if(!number.empty()){
        int num = 0;
        for(int i = 0; i < number.size(); i++){
            num *= 10;
            if(number[i] != 0)
                num += number[i];
        }
        number.clear();
        q.push_back(make_pair('n', num));
    }
}

int main(void){
    string str;
    cin >> str;
    int strLength = str.length();
    for(int i = 0; i < strLength; i++){
        char c = str[i];
        if(isdigit(c)){
            number.push_back(c - '0');
        }
        else{
            addNumber();
            if(c == '-')
                q.push_back(make_pair('o', MINUS));
            else
                q.push_back(make_pair('o', PLUS));
        }
    }
    addNumber();

    // while(!q.empty()){
    //     cout << q.front().second << " ";
    //     q.pop_front();
    // }
    // cout << endl;
    // cout << strLength << endl;

    int deqSize = q.size();
    // sum, numbers
    vector<pair<int, vector<int> > > parVec;
    int sum = q[0].second;
    int minusSum = 0;
    for(int i = 1; i < deqSize; i += 2){
        auto np = q[i];
        int nn = np.second;
        if(nn == PLUS){
            sum += q[i + 1].second;
        }
        else if(nn == MINUS){
            if(q[i + 2].second == 0){
                sum -= q[i + 1].second;
            }
            else{
                minusSum += q[i + 1].second;
                while(true){
                    i += 2;
                    if(q[i].second == MINUS || i > deqSize)
                        break;
                    else if(q[i].second == PLUS)
                        minusSum += q[i + 1].second;
                }
                if(minusSum != 0){
                    sum -= minusSum;
                    minusSum = 0;
                }
            }
        }
    }

    cout << sum << endl;

    return 0;
}