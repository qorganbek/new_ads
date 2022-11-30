#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    pair <int, int> a[m];

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        a[i] = make_pair(x,y);
    }


    cout << "\n";
    for(int i = 0; i < m; i++){
        cout << a[i].first << " " << a[i].second << endl;
    }    
    return 0;
}