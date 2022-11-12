#include <bits/stdc++.h>
using namespace std;

void h(long long n, long long * a){
    string s = "";
    long long d;
    long long q = LONG_LONG_MAX;
    for(int i = 0; i < n; i++){
        if(i == 0){
            s += char(a[i] + 97); 
        }
        if(i > 0){
            d = (a[i] % q) - (a[i - 1]) % q;
            d = d / pow(2, i); 
            s += char((d + 97));
        }
    }
    cout<<s;
}

int main(){
    long long n;
    cin >> n;
    long long a[n];
    for(size_t i = 0; i < n; i++){
        long long  x;
        cin>>x;
        a[i] = x;
    }
    h(n, a);
}