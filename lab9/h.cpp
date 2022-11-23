#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> l(string s){

vector<ll> p(s.size(), 0);

for(ll i = 1; i < s.size(); i++){
    ll j = p[i-1];
    while(j > 0 && s[i] != s[j])j = p[j-1];
    if(s[i] == s[j]){
        j++;
    }
    p[i] = j;
}

return p;
}



int main(){
    string s;
    cin >> s;
    vector<ll> p = l(s);
    int cnt = 0;
    for(int i = 1; i < s.size() - 1; i += 2){
        if((i + 1) % (i + 1 - p[i]) == 0 && (( i + 1) / (i + 1 - p[i]) ) % 2 == 0){
            cnt++;
        }
    }

    cout << cnt;
}