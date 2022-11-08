#include <bits/stdc++.h>

using namespace std;

map<string,double> marks;

void setMarks(){
    marks["A+"] = 4.00;
    marks["A"] = 3.75;
    marks["B+"] = 3.50;
    marks["B"] = 3.00;
    marks["C+"] = 2.50;
    marks["C"] = 2.00;
    marks["D+"] = 1.50;
    marks["D"] = 1.00;
    marks["F"] = 0;

}

bool cmp(pair<pair<string,string> ,double> a, pair<pair<string,string> ,double> b){
    if (a.second == b.second){
        if (a.first.first == b.first.first){
            if (a.first.second == b.first.second) return true;
            return a.first.second < b.first.second;
        }
        return a.first.first < b.first.first;
    }
    return a.second < b.second;
}

int partition(pair<pair<string,string> ,double> *a, int low , int high){
    int i = low - 1;
    pair<pair<string,string> ,double> pivot = a[high];
    for (int j = low; j < high; j++){
        if (cmp(a[j],pivot)){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1], a[high]);
    return i + 1;
}


void qsort(pair<pair<string,string> ,double> *a, int low , int high){
    if (low < high){
       int pivot = partition(a,low,high);
       qsort(a,low,pivot-1);
       qsort(a,pivot+1,high); 
    }
}

int main (){
    setMarks();
    int n;
    cin >> n;
    pair<pair <string,string>, double> a[n];
    for (int i = 0; i < n; i++){
        string name,surname;
        int num;
        cin >> name >> surname >> num;
        int total_credit = 0;
        double gpa = 0;
        for (int j = 0; j < num; j++){
            string grade;
            int credit;
            cin >> grade >> credit;
            gpa += marks[grade]*credit;
            total_credit += credit;
        }
        a[i] = make_pair(make_pair(name,surname),gpa/total_credit);
    }

    qsort(a,0,n-1);
    
    for (int i = 0; i < n; i++){
        cout << fixed << setprecision(3) << a[i].first.first << " " << a[i].first.second << " " << a[i].second << endl;
    }

    return 0;
}