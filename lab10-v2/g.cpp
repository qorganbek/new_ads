#include <bits/stdc++.h>

using namespace std;

bool is_acyclic(pair<int, int> a[], int cut_ind, int cut, int startswith, int m){
    unordered_map<int, int> mp (a,a+m);
    mp.erase(cut);
    queue<int> q;
    q.push(a[cut_ind].first);
    int cnt = 0;
    while (q.size() > 0)
    {
        int cur = q.front();
        q.pop();
        if(cur == 0)continue;
        q.push(mp[cur]);
        cnt++;
        if(cnt > m){
            return false;
        } 
    }
    return true;    
}

int main(){
    int n, m;
    cin >> n >> m;
    pair<int, int> a[m];

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        a[i] = make_pair(x,y); 
    }



    return 0;
}