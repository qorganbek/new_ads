#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    map<pair<int,int>,int> mp;
    string year,day,month;
    year = day = month = "";
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        day = s[0] + s[1];
        month = s[3] + s[4];
        year = s[6] + s[7] + s[8] + s[9];
        pair<int,int> dm = make_pair(stoi(day),stoi(month));
        mp[dm] += stoi(year);
    }

    map<pair<int ,int>, int>::iterator it;

    for (it = mp.begin(); it != mp.end(); it++){
        cout << (*it).first.first << " " << (*it).first.second << " " << (*it).second;
        cout << endl;
    }

    return 0;
}