#include <bits/stdc++.h>

using namespace std;

int a[5001][5001];
int d[5001][5001];
vector<int> red;

vector<int> get_path(int v, int n){
    vector<int> dis(d[v], d[v] + n);
    queue<int> q;
    dis[v] = 0;
    q.push(v);
    while (q.size() > 0)
    {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < n; i++){
            if(a[cur][i] == 1 && dis[i] == -1){
                dis[i] = dis[cur] + 1;
                q.push(i);
            }
        }
    }
    return dis;    
}

int main(){
    int n, m, q;
    cin >> n >> m >> q;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = 0;
            d[i][j] = -1;
        }
    }

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        a[x][y] = 1;
        a[y][x] = 1;
    }

    for(int i = 0; i < q; i++){
        int com, ver;
        cin >> com >> ver;
        if(com == 1){
            red.push_back(ver-1);
        }
        else if (com == 2){
            vector<int> dis = get_path(ver-1,n);
            int min_path = 1e9;
            for(int j = 0; j < red.size(); j++){
                if(dis[red[j]] < min_path && dis[red[j]] != -1){
                    min_path = dis[red[j]];
                }
            }
            if(min_path == 1e9){
                cout << -1 << endl;
            }
            else cout << min_path << endl;
        }
    }

    return 0;
}