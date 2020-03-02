#include <iostream>

using namespace std;

int main(void){
    string str, word;
    int strLen, wordLen;
    int sum = 0;

    //cin >> str >> word;
    getline(cin, str);
    getline(cin, word);

    strLen = str.length();
    wordLen = word.length();

    for(int i = 0; i < strLen; i++){
        for(int j = 0; j < wordLen; j++){
            if(str[i+j] != word[j])
                break;
                
            if(j == (wordLen - 1)){
                i += (wordLen - 1);
                sum++;
            }
        }
    }

    cout << sum << '\n';
    return 0;
}