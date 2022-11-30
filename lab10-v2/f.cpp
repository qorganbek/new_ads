#include <bits/stdc++.h>

using namespace std;


bool search(vector<int> a[], int x, int y, int n){
    queue<int> q;
    int dis[n+1];
    for(int i = 0; i <= n; i++){
        dis[i] = 0;
    }
    dis[x] = 1;
    q.push(x);
    while (q.size() > 0)
    {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < a[cur].size(); i++){
            if(dis[a[cur][i]] == 0){
                dis[a[cur][i]] = 1;
                if(a[cur][i] == y){
                    return true;
                }
                q.push(a[cur][i]);
            }

            
        }
    }
    
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;    
    vector<int> a[n+1];
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int s, t;
    cin >> s >> t;
    string res = search(a, s, t, n) ? "YES" : "NO";
    cout << res;
    return 0;
}