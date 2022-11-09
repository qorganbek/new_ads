#include <iostream>
#include <vector>
using namespace std;

void merge(vector<string> &a, int l1, int r1, int l2, int r2){
    int n1 = r1 - l1 + 1;
    string L[n1];
    for(int i = 0; i < n1; ++i){
        L[i] = a[l1 + i];
    }

    int n2 = r2 - l2 + 1;
    string R[n2];
    for(int i = 0; i < n2; ++i){
        R[i] = a[l2 + i];
    }

    int i = l1;
    int i1 = 0;
    int i2 = 0;

    while(i1 < n1 && i2 < n2){
        if(L[i1].size() <= R[i2].size()){
            a[i++] = L[i1++];
        }else {
            a[i++] = R[i2++];
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

void msort(vector<string> &a, int l, int r){
    if(l < r){
        int m = r - (r - l) / 2;
        msort(a, l, m - 1);
        msort(a, m, r);
        merge(a, l, m - 1 , m, r);
    }
}





int main(){
    vector<vector<string> > D;
    int n;
    cin >> n;
    for (int i = 0; i < n+1; i++){
        string s;
        getline(cin,s);
        vector<string> v;
        string t = "";
        if(i == 0){
            continue;
        }
        for (int j = 0; j < s.size(); j++){
            
            if (j+1 == s.size()){
                t += s[j];
                v.push_back(t);
            }
            if (s[j] == ' '){
                v.push_back(t);
                t = "";
            }
            else t += s[j];
        }
        
        

        msort(v, 0, v.size()-1);

        for (int j = 0; j < v.size(); j++){
            cout << v[j] << " ";
        }
        cout << endl;


        
    }
    return 0;
}