#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = -987654321;
    int stone_size = stones.size();
    int left = 0;
    int right = -987654321;
    for(int num : stones){
        right = max(right, num);
    }

    while(left <= right){
        int mid = (left + right) / 2;
        
        int cnt = 0;
        bool flag = false;
        for(int num : stones){
            if(num - mid >= 0){
                if(cnt) cnt = 0;
            }
            else{
                cnt++;
            }

            if(cnt == k){
                flag = true;
                break;
            }
        }

        if(flag){
            // can't go
            right = mid - 1;
        }
        else{
            answer = max(answer, mid);
            left = mid + 1;
        }
    }
    return answer;
}