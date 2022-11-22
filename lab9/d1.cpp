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
//tauemel#kokshetau
int main(){
    int max = 1;
    vector< pair<int,string> > ans;
    string s; cin >> s;
    s[0] += 32;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string x; cin >> x;
        x[0] += 32;
        vector<int> v = kmp(x + '#' + s);
        x[0] -= 32; 
        int m = 0;
        if(m <= v[v.size()-1]) m = v[v.size()-1];
        for(int j = v.size()-1; j >= 0; j--){
            if(v[j] == v[v.size()-1] && v[v.size()-1] != 0){
                ans.push_back(make_pair(v[j], x));
            }
        }
        if(max < m) max = m;
    }

    vector<string> solve;
    
    for(int i = 0; i < ans.size(); i++){
        if(max == ans[i].first){
            solve.push_back(ans[i].second);
        }
    }

    cout << solve.size() << endl;
    
    for(int i = 0; i < solve.size(); i++){
        cout << solve[i] << endl;
    }

    return 0;
}