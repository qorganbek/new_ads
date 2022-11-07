#include <bits/stdc++.h>

using namespace std;

bool cmp(pair <int, pair<int, int> > a, pair <int, pair<int, int > > b){
    if (a.second.second == b.second.second){
        if (a.second.first == b.second.first){
            if (a.first == b.first) return true;
            return a.first > b.first;
        }
        return a.second.first > b.second.first;
    }
    return a.second.second > b.second.second;
}


int partition(vector<pair <int, pair<int, int >>> &v, int low , int high){
    int i = low - 1;
    pair<int , pair<int ,int>> pivot = v[high];
    for (int j = low; j < high; j++){
        if(cmp(pivot,v[j])){
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[high],v[i+1]);
    return i+1;
}

void qsort(vector<pair<int,pair<int,int>>> &v, int low, int high){
    if (low < high){
        int pivot = partition(v,low,high);
        qsort(v,low,pivot-1);
        qsort(v,pivot+1,high);
    }
}


int main(){
    vector<pair <int, pair<int, int >>> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int day,month,year;
        char w;
        cin >> day >> w >> month >> w >> year;
        v.push_back(make_pair(day,make_pair(month,year)));
    }
    qsort(v,0,n-1);
    
    for (int i = 0; i < n; i++){
        (v[i].first < 10) ? cout << 0 << v[i].first << "-" : cout << v[i].first << "-";
        (v[i].second.first < 10) ? cout << 0 << v[i].second.first << "-" : cout << v[i].second.first << "-";
        cout << v[i].second.second << "\n";
    }
    
    return 0;
}
