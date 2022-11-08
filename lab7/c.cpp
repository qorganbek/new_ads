#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &a, int l1, int r1, int l2, int r2){
    int n1 = r1 - l1 + 1;
    int L[n1];
    for(int i = 0; i < n1; ++i){
        L[i] = a[l1 + i];
    }

    int n2 = r2 - l2 + 1;
    int R[n2];
    for(int i = 0; i < n2; ++i){
        R[i] = a[l2 + i];
    }

    int i = l1;
    int i1 = 0;
    int i2 = 0;

    while(i1 < n1 && i2 < n2){
        if(L[i1] < R[i2]){
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

void msort(vector<int> &a, int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;
        msort(a, l, m);
        msort(a, m + 1, r);
        merge(a, l, m , m + 1, r);
    }
}

int main (){
    map<int, int> f;
    map<int, int> s;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        f[x]++;
    }

    for (int i = 0; i < m; i++){
        int x;
        cin >> x;
        s[x]++;
    }

    map<int,int>::iterator it_f, it_s;
    
    vector<int> ans;
    for (it_f = f.begin(); it_f != f.end(); it_f++){
        for (it_s = s.begin(); it_s != s.end(); it_s++){
            if ((*it_f).first == (*it_s).first){
                if((*it_f).second == (*it_s).second){
                    for(int i = 0; i < (*it_f).second; i++){
                        ans.push_back((*it_f).first);
                    }
                }
                else {
                    for(int i = 0; i < min((*it_f).second,(*it_s).second); i++){
                        ans.push_back((*it_f).first);
                    } 
                }
            }
        
        }     
    }

    msort(ans,0,ans.size()-1);

    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}