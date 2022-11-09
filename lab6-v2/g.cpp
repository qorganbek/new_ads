#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    vector <pair<string,string> > a;

    for (int i = 0; i < n; i++){
        string name, oldname;
        cin >> name >> oldname;
        a.push_back(make_pair(name,oldname));
    }
    
    for (int i = 0; i < n-1; i++){
        for(int j = i + 1; j < n; j++){
            if (a[i].second == a[j].first){
                a[i].second = a[j].second;
                a[j].second = a[j].first = "-";
            }
        }
    }

    map<string,string> m;
    map<string,string>::iterator it;

    for (int i = 0; i < n; i++){
        if (a[i].first == "-"){
            continue;
        }
        else {
            m[(a[i].first)] = a[i].second; 
        }
    }


    cout << m.size() << endl;
    for (it = m.begin(); it != m.end(); it++){
        cout << (*it).first << " " << (*it).second << endl;
    }
    return 0;
}