#include <bits/stdc++.h>
using namespace std;

int h(string s, string t){
    size_t n = s.size();
    size_t m = t.size();
    long long h[n];
    long long p[n];
    long long q = LONG_LONG_MAX;
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
    long long h_t = 0;
    for(size_t i = 0; i < m; i++){
        h_t = (h_t + ((t[i] - int('a') + 1) * p[i]) % q) % q;
    }
    long long cnt = 0;
    for(size_t i = 0; i + m -1 < n; i++){
        long long d = h[i+m-1];
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
            string pattern;
            cin >> pattern;
            a[i] = pattern;
        }
        string s;
        cin >> s;
        int max = 0;
        for(int i = 0; i < n; i++){
            if(h(s, a[i]) > max){
                max = h(s, a[i]);
            }
        }
        vector<string> v;
        for(int i = 0; i < n; i++){
            if(h(s, a[i]) == max){
                v.push_back(a[i]);
            }
        }
        cout<< max <<endl;
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << endl;
        }
    }
}