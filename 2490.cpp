#include <iostream>

using namespace std;

int main(void){
    int T = 3;
    while(T--){

        int bae = 0;
        int deung = 0;
        for(int i = 0; i < 4; i++){
            int n;
            cin >> n;
            if(n == 1)
                deung++;
            else
                bae++;
        }

        if(bae == 1 && deung == 3)
            cout << "A";
        else if(bae == 2 && deung == 2)
            cout << "B";
        else if(bae == 3 && deung == 1)
            cout << "C";
        else if(bae == 4 && deung == 0)
            cout << "D";
        else if(bae == 0 && deung == 4)
            cout << "E";
        cout << endl;
    }
    return 0;
}