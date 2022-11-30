#include <bits/stdc++.h>

using namespace std;

bool q[100001];

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a[n+1];
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }

    return 0;
}