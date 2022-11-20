#include <iostream>
#include <vector>
using namespace std;

size_t f1(string pref){
    for(size_t i = pref.size()-1; i >= 1; i--){
        if(pref.substr(0, i) == pref.substr(pref.size()-i, i)){
            return i;
        }
    }
    return 0;
}


vector<size_t> f(string str){
    size_t n = str.size();
    vector<size_t> v(n);
    for(size_t i = 1; i <= n; i++){
        v[i-1] = f1(str.substr(0,i));
    }
    return v;
}


int main(){
    string text, pat;
    cin >> text >> pat;
    string str = pat + '#' + text;
    vector<size_t> v = f(str);
    for (size_t i = 0; i < v.size(); i++){
        if (v[i] == pat.size()){
            cout << "found" << endl;
            return 0;
        }
    }
    cout << "not found" << endl;
    return 0;
}