#include <bits/stdc++.h>

using namespace std; 

vector<int>g_roadways[410];

vector<int>g_airlanes[410]; 

int ar[410][410]; 

int main(){ 
    int n, m; 
    cin >> n >> m; 
    for(int i = 0; i < m; i++){ 
        int a, b; 
        cin >> a >> b; 
        a--; b--; 
        g_roadways[a].push_back(b); 
        g_roadways[b].push_back(a); 
        ar[a][b] = 1; 
        ar[b][a] = 1; 
    } 
    for (int i = 0; i < n; i ++){ 
        for (int j = 0; j < n; j ++){ 
            if (ar[i][j] == 0 and i != j){ 
                g_airlanes[i].push_back(j); 
            } 
        } 
    } 
    queue<int> q1; 
    vector<int> d1(n+1); 
    vector<bool> used1(n+1); 
    q1.push(0); 
    used1[0] = true; 
    while(not q1.empty()){ 
        int v = q1.front(); 
        q1.pop(); 
        for(int i = 0;i < g_roadways[v].size(); i++){ 
            int to = g_roadways[v][i]; 
            if(not used1[to]){ 
                used1[to] = true; 
                q1.push(to); 
                d1[to] = d1[v] + 1; 
            } 
        } 
    } 
    queue<int> q2; 
    vector<int> d2(n+1); 
    vector<bool> used2(n+1); 
    q2.push(0); 
    used2[0] = true; 
    while(not q2.empty()){ 
        int v = q2.front(); 
        q2.pop(); 
        for(int i = 0;i < g_airlanes[v].size(); i++){ 
            int to = g_airlanes[v][i]; 
            if(not used2[to]){ 
                used2[to] = true; 
                q2.push(to); 
                d2[to] = d2[v] + 1; 
            } 
        } 
    } 

    int res = (not used1[n-1] or not used2[n-1])  ? -1 : max(d1[n-1], d2[n-1]);
    
    cout << res;

    return 0;
}