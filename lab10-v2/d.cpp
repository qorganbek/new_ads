#include <bits/stdc++.h>

using namespace std;

bool isred[5000];

int check(vector <int> a[], int t, int n){
    if(isred[t] == true){    
        return 0;
    }
    int dis[n + 1];
    int vis[n + 1];
    queue <int> q;
    for(int i = 0; i <= n  ; i++){
        dis[i] = -1;
        vis[i] = false;
    }
    q.push(t);
    dis[t] = 0;
    vis[t] = 1;
    while(q.size() > 0){
        int cur = q.front();
        q.pop();
        for(int i = 0; i < a[cur].size(); i++){
            if(vis[a[cur][i]] == 0) {
                vis[a[cur][i]] = 1;
                dis[a[cur][i]] = dis[cur] + 1;
                q.push(a[cur][i]);
                if(isred[a[cur][i]] == true){
                    return dis[a[cur][i]];
                }
            }
        }
    }
    return -1;
}

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector <int> a[n + 1];
    while(m--){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    while(q--){
        int r, v;
        cin >> r >> v;
        if(r == 1){
            isred[v] = true;
        }
        else {
            cout << check(a, v, n) << endl;
        }
    }
    return 0;
}