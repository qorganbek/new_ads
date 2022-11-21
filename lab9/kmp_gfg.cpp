#include <bits/stdc++.h>

using namespace std;

vector <size_t> kmp(string s){
    size_t n = s.size();
    vector<size_t> v(n);
    for (int i = 1; i < n; i++){
        size_t j = v[i-1];
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
    string text = "bcabcab";
    // string pattern = "bcabcab";
    // string str = pattern + '#' + text;
    vector<size_t> v = kmp(text);
    for(int i = 0; i < v.size(); i++){
        // if(v[i] == pattern.size()){
            cout <<v[i]  << " ";
        //     return 0;
        // }
    }
    // cout << "not found!";
    return 0;
}