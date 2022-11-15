#include <bits/stdc++.h>

#define ll long long

using namespace std;
size_t ind = 0;
void f(string t, string s){
    size_t n = t.size();
    size_t m = s.size();

    ll h[n];
    ll p[n];
    ll q = LONG_LONG_MAX;

    p[0] = 1;

    for(size_t i = 1; i < max(n, m); ++i){
        p[i] = (p[i - 1] * 31) % q;
    }

    for(size_t i = 0; i < n; ++i){
        h[i] = ((t[i] - int('a') + 1) * p[i]) % q;
        if(i > 0){
            h[i] = (h[i] + h[i - 1])  % q;
        }
    }
    ll h_s = 0;
    for(size_t i = 0; i < m; ++i){
        h_s = (h_s + ((s[i] - int('a') + 1) * p[i]) % q) % q;
    }

    for(size_t i = 0; i + m - 1 < n; i++){
        ll d = h[i + m - 1];
        if(i > 0){
            d -= h[i-1];
        }
        if( d == h_s * p[i]  && t.substr(i, m) == s){
            ind = i;
        }
    }

}

int main(){
    string text, pattern;
    cin >> text >> pattern;
    f(text, pattern);
    cout << ind;
    return 0;
}