#include <bits/stdc++.h>
using namespace std;
int main () {
    int n;
    cin >> n;
    string st;
    cin >> st;
    queue <int> k , s;
    for (int i = 0; i < st.size(); i++){
        if (st[i] == 'K'){
            k.push(i);
        }
        else {
            s.push(i);
        } 
    }
        while(!s.empty() and !k.empty()){
        if(s.front() < k.front()){
            s.push(s.front() + n);
        }
        else{
           k.push(k.front() + n); 
        }  
        s.pop();
        k.pop();
    }
    if (s.empty()){
        cout << "KATSURAGI";
    }
    else {
        cout << "SAKAYANAGI";
    }
    return 0;
}