#include <bits/stdc++.h>

using namespace std;


bool haspath(unordered_map<int, int> mp, int src, int dst){
    if(src == dst){
        return true;
    }
    if(haspath(mp,mp[src],dst)) return true;
    return false;
}



int main(){
    unordered_map<int, int> mp;
    int n, m;
    cin >> n >> m;
    int f;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        if(i == 0)f = x;
        mp[x] = y; 
    }

    int s, t;
    cin >> s >> t;
    s--; t--;

    string res = haspath(mp, s, t) ? "YES" : "NO";

    cout << res;

    return 0;
}