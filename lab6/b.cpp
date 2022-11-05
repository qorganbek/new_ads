#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &a, int low, int high){
    int i = low - 1;
    int pivot = high;
    for (int j = low; j < high; j++){
        if(a[j] < a[pivot]){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[pivot]);
    return i + 1;
}

void qsort(vector<int> &a, int low, int high){
    if(low < high){
        int pivot = partition(a,low,high);
        qsort(a,low,pivot-1);
        qsort(a,pivot+1,high);
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

    qsort(ans,0,ans.size()-1);

    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}