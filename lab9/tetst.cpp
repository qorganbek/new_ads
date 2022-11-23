#include <bits/stdc++.h>

using namespace std;

struct vertex{
    int r, c;
    vertex(int r, int c){
        this->r = r;
        this->c = c;
    }
};

queue<vertex> q;
int t[100][100];

int main(){
    int n, m;
    int r, c;
    cin >> n >> m >> r >> c;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            t[i][j] = -1;
        }
    }
}