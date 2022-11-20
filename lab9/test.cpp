#include <iostream>

using namespace std;

int main(){
    string t = "kokshetau";
    string s = "taukent";
    for (int i = 0; i < s.size(); i++){
        for (int j = t.size()-1; j >= 0; j--){
            if (t.substr(t.size()-j,j) == s.substr(0,i)){
                cout << s.substr(0,i);
            }
        }
    }


    return 0;
}