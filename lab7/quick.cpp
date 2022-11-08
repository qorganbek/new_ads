#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<pair<string, string>, double> a, pair<pair<string, string>, double> b){
    if(a.second == b.second){
        if(a.first.first == b.first.first){
            if(a.first.second == b.first.second) return true;
            return a.first.second < b.first.second;
        }
        return a.first.first < b.first.first;
    }
    return a.second < b.second;
}

int partition(pair<pair<string, string>, double> *a, int low, int high){
    int i = low-1;
    pair<pair<string, string>, double> pivot = a[high];
    for(int j = low; j < high; j++){
        if(cmp(a[j],pivot )){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[high]);
    return i+1;
}
void qsort(pair<pair<string, string>, double> *a, int low, int high){
    if(low<high){
        int pivot = partition(a, low, high);
        qsort(a, low, pivot-1);
        qsort(a, pivot+1, high);
    }
}

int main(){
    
    int n; cin >> n;
    pair<pair<string,string>, double> a[n];
    for(int i = 0; i < n; i++){
        string name, surname, grade;
        int all;
        cin >> surname >> name >> all;
        float gpa = 0;
        float credits = 0;
        for(int j = 0; j < all; j++){
            
            string k; int x;
            cin >> k >> x;
            credits += x;
            if(k == "A+") gpa += 4*x;
            else if(k == "A") gpa += 3.75*x;
            else if(k == "B+") gpa += 3.5*x;
            else if(k == "B") gpa += 3*x;
            else if(k == "C+") gpa += 2.5*x;
            else if(k == "C") gpa += 2*x;
            else if(k == "D+") gpa += 1.5*x;
            else if(k == "D") gpa += 1*x;
            else if(k == "F") gpa += 0*x;
        }
        a[i] = make_pair(make_pair(surname,name),gpa/credits);
    }
    qsort(a, 0, n-1);
    for(int i = 0; i < n; i++){
        cout << fixed << setprecision(3) << a[i].first.first << " " << a[i].first.second << " " << a[i].second << endl;
    }
      
}