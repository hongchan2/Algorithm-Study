#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
#define endl '\n'
#define TEST cout << "TEST" << endl;
 
long long k;
vector<long long> room_number;
vector<long long> answer;

int main(void){
    cin >> k;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        long long n1; cin >> n1;
        room_number.push_back(n1);
    }

    unordered_map<long long, long long> m;
    
    for(long long num : room_number){
        auto iter = m.find(num);
        
        if(iter == m.end()){
            m.insert(make_pair(num, 0));
            answer.push_back(num);
        }
        else{
            long long i = num + 1;

            if(iter->second != 0){
                i += iter->second;
                // cout << "ACTIVE ] " << i << endl;
            }

            for(; i <= k; i++){
                iter = m.find(i);

                if(iter != m.end()){
                    if(iter->second != 0){
                        i += iter->second;
                        // cout << "ACTIVE ] " << i << endl;
                    }
                    continue;
                }
                
                m.insert(make_pair(i, 0));
                m[num] = i - num;
                answer.push_back(i);
                break;
            }
        }
    }
    
    for(auto n : answer)
        cout << n  << " ";
    cout << endl;
    return 0;
}