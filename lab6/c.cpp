#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int partitition(vector<int> &a, int low, int high){
    int i = low - 1;
    int pivot = high;
    for (int j = low; j < high; j++){
        if(a[j] < a[pivot]){
            i++;
            swap(a[j],a[i]);
        }
    }
    swap(a[pivot],a[i+1]);
    return i + 1; 
}

void qsort(vector<int> &a, int low, int high){
    if (low < high){
        int pivot = partitition(a,low,high);
        qsort(a,low,pivot-1);
        qsort(a,pivot+1,high);
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> ans;
    int mini = 1e9;
    //o(n^2)
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (abs(a[i] - a[j]) < mini){
                mini = abs(a[i] - a[j]);
            }
        }
    }
    //o(n^2)
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (abs(a[j] - a[i]) == mini){
                ans.push_back(a[i]);
                ans.push_back(a[j]);
            }
        }
    }

    qsort(ans,0,ans.size()-1);

    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    
    return 0;
}