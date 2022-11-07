#include <bits/stdc++.h>

using namespace std;

int main(){
    map <string, string> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        string s,t;
        cin >> s >> t;
        m[s] = t;
    }
    map<string,string>::iterator it;

          

    for (it = m.begin(); it != m.end(); it++){
        cout << (*it).first << " " << (*it).second << endl;
    }
    return 0;
}