#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &a, int low, int high){
    int i = low - 1;
    int pivot = high;
    for (int j = low; j < high; j++){
        if (a[j] > a[pivot]){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[pivot], a[i + 1]);
    return i + 1; 
}
void qsort(vector<int> &a, int low, int high){
    if(low < high){
        int pivot = partition(a,low,high);
        qsort(a, low, pivot - 1);
        qsort(a, pivot + 1, high);
    }
}

int main (){
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }    
    }
    
    for (int i = 0; i < m; i++){
        vector<int> row;
        for (int j = 0; j < n; j++){
            row.push_back(a[j][i]);
        }
        qsort(row,0,n-1);
        for (int j = 0; j < n; j++){
          a[j][i] = row[j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}