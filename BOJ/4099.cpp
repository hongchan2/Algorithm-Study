#include <iostream>
#include <string>

using namespace std;

int main(void){
    string jae;
    string doc;
    cin >> jae >> doc;

    if(jae.size() >= doc.size())
        cout << "go";
    else
        cout << "no";

    return 0;
}