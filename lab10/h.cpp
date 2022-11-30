#include <bits/stdc++.h>

using namespace std;


char a[100][100];
queue<pair<int,int>> q;

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    return 0;
}