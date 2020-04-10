#include <string>
#include <vector>

#include <queue>

using namespace std;

bool check[51] = { 0, };

int solution(string begin, string target, vector<string> words) {
    int wordsLen = words.size();
    int beginLen = begin.length();

    int answer = 0;
    queue<string> q;
    q.push(begin);
    while(!q.empty()){
        int qCnt = q.size();
        while(qCnt--){
            string curStr = q.front(); q.pop();

            if(curStr == target){
                return answer;
            }

            for(int i = 0; i < wordsLen; i++){
                int correctCnt = 0;
                for(int j = 0; j < beginLen; j++){
                    if(check[i]) break;
                    if(curStr[j] == words[i][j]) continue;

                    correctCnt++;
                    if(correctCnt > 1) break;
                }

                if(correctCnt == 1){
                    check[i] = true;
                    q.push(words[i]);
                }
            }

        }
        answer++;
    }

    return 0;
}