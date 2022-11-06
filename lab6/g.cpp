#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    map<string,string> mp;
    for (int i = 0; i < n; i++){
        string s,t;
        cin >> s >> t;
        mp[s] = t;
    }
    map<string,string> ans;
    map<string,string>::iterator it1,it2;
    for (it1 = mp.begin(); it1 != mp.end(); it1++){
        for (it2 = mp.begin(); it2 != mp.end(); it2++){
            if ((*it1).second == (*it2).first){
                ans[(*it1).first] = (*it2).second;   
            }
        }
        
    }

    for (it1 = ans.begin(); it1 != ans.end(); it1++){
        cout << (*it1).first << " " << (*it1).second << endl;
    }

    return 0;
}