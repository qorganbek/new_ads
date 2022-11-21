#include <iostream>

using namespace std;

int main(){
    string t = "kokshetau";
    string s = "taukent";
    for(int i = 0; i < t.size(); i++){
        cout << t.substr(t.size()-i,i) << endl;
    }


    return 0;
}