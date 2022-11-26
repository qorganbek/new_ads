#include <iostream>
#include <queue>

using namespace std;

struct vertex{
    int r;
    int c;
    vertex(int r, int c){
        this->r = r;
        this->c = c;
    }
};

queue<vertex> q;
int ti[1001][1001];

void step(int r, int c, int n, int m, int t){
    if(r <= n  && c <= m && r >= 1 && c >=1 && ti[r][c] == -1){
        ti[r][c] = t;
        q.push(vertex(r, c));
    }   
}


int main(){

    int n, m;
    int r, c;
    cin >> n >> m;
        if(n == 1 && m == 1){
        cout << 0;
        return 0;
    }
    
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> ti[i][j];
            if(ti[i][j]== 0){
                ti[i][j] = -7;
            }
            else if(ti[i][j] == 2){
                ti[i][j] = 0;
                q.push(vertex(i,j));
            }
            else if(ti[i][j] == 1){
                ti[i][j] = -1;
            }
        }
    }



    while(q.size() > 0){
        vertex cur = q.front();
        q.pop();
        int t = ti[cur.r][cur.c];
        step(cur.r + 1, cur.c, n, m, t + 1);
        step(cur.r - 1, cur.c, n, m, t + 1);
        step(cur.r, cur.c + 1, n, m, t + 1);
        step(cur.r, cur.c - 1, n, m, t + 1);
    }

    int mx = -1;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(ti[i][j] == -1){
                cout << -1;
                return 0;
            }
            mx = max(mx, ti[i][j]);
        }
    }   

    cout << mx;

    return 0;
}