#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;

ll min_dis(ll ans[], bool visited[]){
    ll min = 1e10 + 7, min_index;

    for (int v = 0; v < n; v++){
        if (visited[v] == false && ans[v] <= min){
            min = ans[v], min_index = v;
        }
    }
 
    return min_index;
}


int main(){
    cin >> n;
    vector<pair<ll, ll>> vec;
    for(int i = 0; i < n; i++){
        ll x, y;
        cin >> x >> y;
        vec.push_back(make_pair(x, y));
    }

    vector<vector<ll>> a;
    for(int i = 0; i < n; i++){
        vector<ll> a1;
        for(int j = 0; j < n; j++){
            a1.push_back(abs(vec[i].first - vec[j].first) + abs(vec[i].second - vec[j].second));
        }

        a.push_back(a1);
    }    


    
    ll ans[n];
    bool visited[n];

    for(int i = 0; i < n; i++){
        ans[i] = 1e10 + 7;
        visited[i] = false;
    }
    ans[0] = 0;

    for(int cnt = 0; cnt < n; cnt++){
        ll u = min_dis(ans, visited);
        visited[u] = true;
        for (int v = 0; v < n; v++){
            if (not visited[v] and a[u][v] != 0 and ans[u] != 1e10 + 7 and ans[u] < ans[v] and a[u][v] < ans[v]){
                    ans[v] = max(ans[u], a[u][v]);
            }
        }
    }
    cout << ans[n-1];
    return 0;
}