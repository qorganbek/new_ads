#include <bits/stdc++.h>

#define ll long long

using namespace std;

void h(string s){
    size_t n = s.size();
    ll p[n];
    ll h[n];
    ll q = LONG_LONG_MAX;
    p[0] = 1;
    
    for(size_t i = 1; i < n; i++){
        p[i] = (p[i-1] * 31) % q;
    }
    
    for(int i = 0; i < n; i++){
        h[i] = ((s[i] - int('a') + 1) * p[i]) % q;
        if(i > 0){
            h[i] = (h[i] + h[i - 1]) % q;
        }
    }
    
    int cnt = 0;
    
    for(size_t i = 1; i <= n; i++){
        set <long long> h_s;
        for(size_t j = 0; j < n - i + 1; j++){
            long long cur_h = h[j + i - 1];
            if(j > 0){
                cur_h -= h[j - 1];
            }
            cur_h *= p[n - j - 1];
            h_s.insert(cur_h);
        }
        cnt +=  h_s.size();
    }
    cout<<cnt;
}


int main(){
    string s;
    cin>>s;
    h(s);
}