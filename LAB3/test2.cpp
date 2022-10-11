#include <iostream>
using namespace std;


bool bs(int a[], int n, int x){
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (x < a[m]){
            r = m -1;
        }
        else if (x == a[m]){
            return 1;
        }
        else {
            l = m + 1;
        }
    }
    return 0;
    
}




int main () {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int x;
    cin >> x;
    string res = bs(a,n,x) ? "Yes" : "No";
    cout << res;
    return 0;
}