#include <iostream>
using namespace std;

int ls(int a[], int n, int l1 , int r1 , int l2 , int r2){
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (l1 <= a[i] && a[i] <= r1 || l2 <= a[i] && a[i] <= r2){
            cnt++;
        } 
    }
    return cnt;
}




int main (){
    int n,q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < q; i++){
        int l1,r1,l2,r2;
        cin >> l1 >> r1 >> l2 >> r2;
        cout << ls(a,n,l1,r1,l2,r2);
        cout <<"\n";
    }
    return 0;
}