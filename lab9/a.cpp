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

bool check(string s, string x){
    vector<int> v = kmp(x + '#' + s);
    for(int i = 0; i < v.size(); i++){
        if(v[i] == x.size()) return true;
    }
    return false;
}

int main(){
    string s, x;
    cin >> s >> x;
    int cnt = 1;
    string temp = s;

    while (x.size() > s.size())
    {
        cnt++;
        s += temp;
    }
    if(check(s,x)){
        cout << cnt;
        return 0;
    }
    else {
        s += temp;
        if(check(s,x)){
            cout << cnt+1;
            return 0;
        }   
    }
    cout << -1;
    return 0;
}