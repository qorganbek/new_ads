#include <iostream>
#include <vector>
using namespace std;

int bs(int a[], int x,int n){
    int ind = -1;
    int l,r;
    l = 0;
    r = n - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (a[m] >= x){
            ind = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }  
    }
    return ind;
}

void print(int a[],int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}

int main (){
    int n,m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (i) a[i] += a[i-1];
    }
    for (int i = 0; i < m; i++){
        int x;
        cin >> x;
        cout << bs(a,x,n) + 1 << "\n";
    }
    return 0;
}