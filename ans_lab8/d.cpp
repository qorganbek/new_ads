#include <bits/stdc++.h>

#define ll long long

using namespace std;

int f(string s, string t){
    size_t n = s.size();
    size_t m = t.size();
    ll h[n];
    ll p[n];
    ll q = LONG_LONG_MAX;
    p[0] = 1;
    for(size_t i = 1; i < max(n, m); i++){
        p[i] = (p[i-1] * 31) % q;
    }
    for(size_t i = 0; i < n; i++){
        h[i] = ((s[i] - int('a') + 1) * p[i]) % q;
        if(i > 0){
            h[i] =  (h[i] + h[i - 1]) % q;
        }
    }
    ll h_t = 0;
    for(size_t i = 0; i < m; i++){
        h_t = (h_t + ((t[i] - int('a') + 1) * p[i]) % q) % q;
    }
    ll cnt = 0;
    for(size_t i = 0; i + m -1 < n; i++){
        ll d = h[i+m-1];
        if(i > 0){
            d -=  h[i - 1];
        }
        if(d == h_t * p[i] && s.substr(i, m) == t){
            cnt++;
        }
    }
    return cnt;

}

int main(){
    int n;
    while(cin >> n){
        if(n == 0){
            return 0;
        }
        string a[n];
        
        for(int i = 0; i < n; i++){
            string pat;
            cin >> pat;
            a[i] = pat;
        }
        
        string s;
        
        cin >> s;
        
        int max = 0;
        
        for(int i = 0; i < n; i++){
            if(f(s, a[i]) > max){
                max = f(s, a[i]);
            }
        }
        vector <string> v;
        
        for(int i = 0; i < n; i++){
            if(f(s, a[i]) == max){
                v.push_back(a[i]);
            }
        }
        cout << max <<endl;
        
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << endl;
        }
    }
}