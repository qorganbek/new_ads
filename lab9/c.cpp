#include <bits/stdc++.h>

using namespace std;

vector<int> kmp(string s){
    int n = s.size();
    vector<int> v(n);
    for(int i = 1; i < n; i++){
        int j = v[i-1];
        while (j > 0 && s[j] != s[i])
        {
            j = v[j-1];
        }
        if(s[i] == s[j]){
            v[i] = j + 1;
        }
        
    }
    return v;
}

int main(){
    string s, t;
    cin >> s >> t;
    vector<int> v = kmp(s+'#'+t+t);
    for(int i = 0; i < v.size(); i++){
        if(v[i] == s.size()){
            cout << i - 2 * s.size();
            return 0;
        }
    } 
    cout << -1;
    return 0;
}
//kokshetau#tauemel
