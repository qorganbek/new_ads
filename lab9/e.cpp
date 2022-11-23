#include <bits/stdc++.h>

using namespace std;

vector <int> kmp(string s){
    int n = s.size();
    vector<int> v(n);
    for(int i = 1; i < n; i++){
        int j = v[i-1];
        while (j>0 && s[j] != s[i]){
            j = v[j-1];
        }
        if(s[i] == s[j]){
            v[i] = j+1;
        }
    }
    return v;
}

int main(){
    int n, k; 
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s >> k;
        int ans = s.size();
        int res = kmp(s)[ans-1];
        ans += (ans-res)*(k-1);
        cout << ans << endl;
    }
}