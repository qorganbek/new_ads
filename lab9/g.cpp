#include <bits/stdc++.h>

using namespace std;

vector<int> kmp(string s){
    int n = s.size();
    vector<int> v(n);
    for(int i = 1; i < n; i++){
        int j = v[i-1];
        while (j > 0 && s[i] != s[j])
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
    string s; cin >> s;
    vector<int> v = kmp(s + '#' + s);
    cout << v[v.size()-1] - v[s.size()-1];
    return 0;
}