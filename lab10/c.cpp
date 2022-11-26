#include <bits/stdc++.h>
#define ll long long
using namespace std;
//6968 7875
//5249
//7875 10498
//7875 5248
int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll> v;
    while (n != m){
        if(abs(m - (n * 2)) > abs(m - n + 1)){
            n *= 2;
        }
        else n--;
        v.push_back(n);
    }
    cout << v.size() << endl;

    for(ll i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    return 0;
}