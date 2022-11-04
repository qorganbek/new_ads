#include <iostream>
#include <vector>
#include <set>

using namespace std;

int partition(vector<int> &a, int low, int high){
    int i = low - 1;
    int pivot = high;
    for (int j = low; j < high; j++){
        if (a[j] < a[pivot]){
            i++;
            swap(a[j],a[i]);
        }
    }
    swap(a[pivot],a[i + 1]);
    return i + 1;
}

void qsort(vector<int> &a, int low, int high){
    if (low < high){
        int pivot = partition(a,low,high);
        qsort(a,low,pivot - 1);
        qsort(a,pivot + 1,high);
    }
}

int main (){
    vector<int> v;
    int n, m;
    set<int> b;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < m; i++){
        int x;
        cin >> x;
        b.insert(x);
    }   
    vector<int> s2(b.begin(),b.end());
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (a[i] == s2[j]){
                v.push_back(a[i]);
            }
        }
    }
    qsort(v,0,v.size()-1);

    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }

    return 0;
}