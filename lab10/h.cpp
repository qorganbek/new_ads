#include <iostream>
#include <queue>

struct vertex
{
    int r, c;
    vertex(int r, int c){
        this->r = r;
        this->c = c;
    }
};


using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int a[n][m];
    queue <vertex> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 1){
                a[i][j] = -1;
                q.push(vertex(i,j));
            }
        }
    }


    while (q.size() > 0){

    }

    
    return 0;
}