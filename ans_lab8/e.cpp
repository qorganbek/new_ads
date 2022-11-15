#include <bits/stdc++.h>

#define ll long long

using namespace std;

void f(ll n, ll * a){
    string s = "";
    
    ll dp;

    ll qd = LONG_LONG_MAX;
    
    for(ll i = 0; i < n; i++){
        if(i == 0){
            s += char(a[i] + 97); 
        }
        if(i > 0){
            dp = (a[i] % qd) - (a[i - 1]) % qd;
            dp = dp / pow(2, i); 
            s += char((dp + 97));
        }
    }
    cout << s;
}

int main(){
    ll n;
    cin >> n;
    ll a[n];
    for(size_t i = 0; i < n; ++i){
        ll x;
        cin >> x;
        a[i] = x;
    }
    f(n, a);
}