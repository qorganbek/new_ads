#include <bits/stdc++.h>

using namespace std;

vector<size_t> kmp(string s){
    size_t n = s.size();
    vector<size_t> v(n);
    for (int i = 1; i < n; i++){
        size_t j = v[i-1];
        while (j > 0 && s[i] != s[j]){
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
    string str = t + '#' + s;
    vector<size_t> v = kmp(str);
    vector<size_t> ans;
    for(int i = 0; i < v.size(); i++){
        if(v[i] == t.size()){
            ans.push_back(i-t.size()-t.size()+1);
        }
        // cout << v[i] << " ";
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}