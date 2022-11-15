#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll f(string s){
    size_t n = s.size();
    ll p[n];
    ll q = 1e9 + 7;
    p[0] = 1;
    for(size_t i = 1; i < n; i++){
        p[i] = (p[i - 1] * 11) % q;
    }
    ll num = 0;
    for(size_t i = 0; i < n; i++){
        num = (num + ((s[i] - 47) * p[i]) % q) % q;
    }
    return num;
}



int main(){
    int n;

    cin >> n;
    
    int k = 2 * n;
    
    string a[k];
    
    set<string> s;
    
    for(int i = 0; i < k; i++){
        cin >> a[i];
        s.insert(a[i]);
    } 

    int cnt = 0;
    
    for(int i = 0; i < k; i++){
        string num = to_string(f(a[i]));
        if(s.find(num) != s.end()){
                cout << "Hash of string \"" << a[i] << "\" is " << num << "\n"; 
                cnt ++;
            }
        if(cnt == n){
            break;
        }
    }
}