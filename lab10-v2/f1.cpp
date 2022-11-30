#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int a[n][n];
    int d[n];
    for(int i = 0; i < n; i++){
        d[i] = -1;
        for(int j =0; j < n; j++){
            a[i][j] = 0;
        }
    }


    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        a[x-1][y-1] = 1;
        a[y-1][x-1] = 1;        
    }

    int s, t;
    cin >> s >> t;
    s--; t--; 

    queue<int> q;
    q.push(s);
    d[s] = 0;
    while (q.size() > 0)
    {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < n; i++){
            if(d[i] == -1 && a[cur][i] == 1){
                d[i] = d[cur] + 1;
                q.push(i);
            }
        }
    }
    
    string res = d[t] == -1 ? "NO" : "YES";
    cout << res;


    return 0;
}