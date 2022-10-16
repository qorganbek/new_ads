#include <bits/stdc++.h>
using namespace std;


int bs(int a[], int n, int l1 , int r1 , int l2 , int r2){
    int cnt = 0;
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (a[m] > r1){
            r = m - 1;
        }
        else if (a[m] < l1){
            l = m + 1;
        }
        else if (a[m] >= l1 && r1 >= a[m]){
            cnt = m + 1;
            break;
        }
    }
    return cnt;
}
//1 2 3 5 8 13 23    1 5
// cnt  = 4;
// 





int main (){
    int n,q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    for (int i = 0; i < q; i++){
        int l1, r1 , l2 , r2;
        cin >> l1 >> r1 >> l2 >> r2;
        cout << bs(a,n,l1,r1,l2,r2);
        cout << "\n"; 
    }
    return 0;
}