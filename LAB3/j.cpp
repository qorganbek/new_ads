#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int arrSum(int a[], int n, int k){
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(a[i]%k == 0 && a[i] >= k) sum += a[i]/k;
        else sum += (a[i]/k)+1;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, h;
    cin >> n >> h;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int l = 1;
    int r = pow(10, 9);
    int ans = r;
    while(l <= r){
        int m = l + (r-l)/2;
        if(arrSum(a, n, m) <= h){
            ans = min(ans, m);
            r = m-1;
        }
        else{
            l = m+1;
        }
    }
    cout << ans << endl;
    return 0;
}
//