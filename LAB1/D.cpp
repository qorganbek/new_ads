#include <bits/stdc++.h>
using namespace std;
int main () {
    string s;
    cin >> s;
    //sbaabsss
    stack <char> st;
    for (int i = 0; i < s.size(); i++){
        if (st.empty()){
            st.push(s[i]);
        }
        else if (st.top() == s[i]){
            st.pop();
        } 
        else {
            st.push(s[i]);
        }
    }

    if (st.empty()){
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    return 0; 
}