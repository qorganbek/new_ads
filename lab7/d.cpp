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


void merge(pair< pair <string , string>, double> *a, int l1, int r1, int l2, int r2){
    int n1 = r1 - l1 + 1;
    pair< pair <string , string>, double>  L[n1];
    for(int i = 0; i < n1; ++i){
        L[i] = a[l1 + i];
    }

    int n2 = r2 - l2 + 1;
    pair< pair <string , string>, double>  R[n2];
    for(int i = 0; i < n2; ++i){
        R[i] = a[l2 + i];
    }

    int i = l1;
    int i1 = 0;
    int i2 = 0;

    while(i1 < n1 && i2 < n2){
        if(L[i1].second < R[i2].second){
            a[i++] = L[i1++];
        }
        else if (L[i1].second > R[i2].second){
            a[i++] = R[i2++];
        }
        else {
            if (L[i1].first.first < R[i2].first.first){
                a[i++] = L[i1++];
            }
            else if (L[i1].first.first > R[i2].first.first){
                a[i++] = R[i2++];
            }
            else {
                if (L[i1].first.second < R[i2].first.second){
                    a[i++] = L[i1++];
                }
                else if (L[i1].first.second > R[i2].first.second){
                    a[i++] = R[i2++];
                }
                else {
                    a[i++] = L[i1++];
                }
            }
        }
    }
    
    //copy rest of L
    while(i1 < n1){
        a[i++] = L[i1++];
    }

    //copy rest of R
    while(i2 < n2){
        a[i++] = R[i2++];
    }

}


void msort(pair< pair <string, string>, double> *a, int l, int r){
    if (l < r){
        int m = r - (r - l)/2;
        msort(a, l, m-1);
        msort(a, m, r);
        merge(a, l, m-1, m, r);
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

    msort(a,0,n-1);
    
    for (int i = 0; i < n; i++){
        cout << fixed << setprecision(3) << a[i].first.first << " " << a[i].first.second << " " << a[i].second << endl;
    }

    return 0;
}