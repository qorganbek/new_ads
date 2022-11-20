#include <bits/stdc++.h>

#define ll long long

using namespace std;
int cnt = 0;
vector<int> v;
void f(string s, string t){
    size_t s_size = s.size();
    size_t t_size = t.size();

    ll h[s_size], p[s_size];
    ll mod = LONG_LONG_MAX;

    p[0] = 1;

    for (size_t i = 1; i < s_size; i++){
        p[i] = (p[i-1] * 31) % mod;
    }

   
    for (size_t i = 0; i < s_size; i++){
        h[i] = ((s[i] - int('a') + 1) * p[i]) % mod;
        if(i > 0){
            h[i] = (h[i-1] + h[i]) % mod;
        }
    }

    ll h_s = 0;
    for (size_t i = 0; i < t_size; i++){
        h_s = (h_s + ((t[i] - int('a') + 1) * p[i]) % mod) % mod;
    }

    for (size_t i = 0; i + t_size - 1 < s_size; i++){
        ll d = h[i + t_size - 1];
        if (i > 0){
            d = (d - h[i-1]) % mod; 
        }
        if (d == h_s * p[i]){
            cnt++;
            v.push_back(i+1);
        }
    }

}



int main(){
    string s,t;
    cin >> s >> t;
    f(s,t);
    cout << cnt << endl;

    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    return 0;
}