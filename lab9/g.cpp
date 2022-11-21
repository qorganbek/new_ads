#include <bits/stdc++.h>

using namespace std;

vector<size_t> kmp(string s){
    size_t n = s.size();
    vector<size_t> v(n);
    for(size_t i = 1; i < n; i++){
        size_t j = v[i-1];
        while (j > 0 && s[j] != s[i])
        {
            j = v[j-1];
        }
        if(s[i] == s[j]) v[i] = j + 1; 
    }
    return v;
}


int main(){
    string s;
    cin >> s;
    vector<size_t> v = kmp(s);
    sort(v.begin(), v.end());
    cout << v[v.size()-2];
    return 0;
}