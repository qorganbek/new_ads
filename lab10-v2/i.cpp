#include <bits/stdc++.h>

using namespace std;

bool q[100001];

bool ispassed(vector<int> v, int x){
    for(int i = 0; i < v.size(); i++){
        if(v[i] == x)return false;
    }
    return true;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a[n+1], ans;
    queue<int> q;
    int cnt = 1;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        if(x == 1 && q.size() == 0)q.push(1);
        a[x].push_back(y);
    }

    ans.push_back(1);
    
    while (ans.size() != n){
        int cur = q.front();
        q.pop();
        for(int i = 0; i < a[cur].size(); i++){
            if(ispassed(ans, a[cur][i])){
                q.push(a[cur][i]);
                a->push_back(a[cur][i]);
            }
        }   
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}