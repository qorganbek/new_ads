#include <iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    pair<int,int> a[m];
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        a[i] = make_pair(x,y);
    }
    int s, t;
    cin >> s >> t;
    for(int i = 0; i < m; i++){
        if((a[i].first == s && a[i].second == t) || (a[i].second == s && a[i].first == t)){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}