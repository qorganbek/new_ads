#include <bits/stdc++.h>
using namespace std;
bool have;
void bs(vector<int> v,int index,int x,int size){
    if (have){
        return;
    }
    int l = 0;
    int r = v.size() - 1;
    if (index % 2 == 0){
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (v[m] == x){
                cout << index << " " << m << endl;
                have = true;
                return;
            }
            else if (v[m] > x){
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
    }
    else {
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (v[m] == x){
                cout << index << " " << m << endl;
                have = true;
                return;
            }
            else if (v[m] > x){
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }        
    }
    if (size == index){
        cout << -1 << endl;
    }
}

int main (){
    int q;
    cin >> q;
    int a[q];
    for (int i = 0; i < q; i++){
        cin >> a[i];
    }
    vector<vector<int>> v;
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        vector <int> row;
        for (int j = 0; j < m; j++){
            int x;
            cin >> x;
            row.push_back(x);
        }
        v.push_back(row);
    }
    
    for (int i = 0; i < q; i++){
        have = false;
        for (int j = 0; j < v.size(); j++){
            bs(v[j],j,a[i],v.size()-1);
        }
    }
    return 0;
}