#include <bits/stdc++.h>
using namespace std;


pair <bool,int> bs(vector<int> &v, int index, int x, int l, int r){
    if (l > r){
        return {-1,-1};
    }
    int m = l + (r - l) / 2;
    if (v[m] == x){
        return {true,m};
    }
    else if (v[m] > x){
        return index % 2 == 0 ? bs(v,index,x,m+1,r) : bs(v,index,x,l,m-1);
    }
    else {
        return index % 2 == 0 ? bs(v,index,x,l,m-1) : bs(v,index,x,m+1,r);
    }
}

pair <int,int> res(vector<vector<int>> &v, int x){
    int l,r;
    l = 0;
    r = v.size() - 1;
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (m % 2 == 0){
            if(v[m][0] >= x && v[m][v.size()-1]){
                pair<bool,int> p = bs(v[m],m,x,0,v[m].size()-1);
                if (p.first){
                    return {m,p.second};
                }
            }
            else if(v[m][0] < x){
                r = m - 1;
            }
            else if (v[m][v[m].size()-1] > x){
                l = m + 1;
            }
        }
        else {

        }
    }
    
}





int main (){
    int q;
    cin >> q;
    int a[q];
    for (int i = 0; i < q; ++i){
        cin >> a[i];
    }
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++){
        vector<int> row;
        for (int j = 0l; j < m; j++){
            int x;
            cin >> x;
            row.push_back(x);
        }
        v.push_back(row);
    }

    return 0;
}