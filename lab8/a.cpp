#include <iostream>

#define ll long long

using namespace std;

void h(string s){
    size_t size = s.size();
    ll h[size], p[size];
    ll mod = 1e9 + 7;
    p[0] = 1;
    for (int i = 1; i < size; i++){
        p[i] = (p[i-1] * 11) % mod;
    }

    for (int i = 0; i < size; i++){
        h[i] = ((s[i] - 46) * p[i]) % mod;
        if (i > 0){
            h[i] = (h[i] + h[i-1]) % mod;
        }
    }

    for (int i = 0; i < size; i++){
        cout << "Hash of string " << h[i] << endl;
    }

}



int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
    }

    return 0;
}