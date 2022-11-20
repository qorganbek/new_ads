#include <iostream>
#include <vector>

using namespace std;

vector <size_t> kmp(string s){
    size_t n = s.size();
    vector <size_t> v(n);
    for (size_t i = 1; i < n; i++){
        size_t j = v[i-1];
        while (s[i] != s[j] && j > 0)
        {
            j = v[j-1];
        }
        if(s[i] == s[j]){
            v[i] = j + 1;
        }
    }
    return v;
}



int main(){
    vector<string> ans;
    string s;
    cin >> s;
    s[0] += 32;
    size_t n;
    cin >> n;
    for (size_t i = 0; i < n; i++){
        string x;
        cin >> x;
        x[0] += 32;
        for(size_t j = s.size()-1; j <= 1; j--){
            string str = s.substr(s.size()-j, j) + '#' + x;
            vector<size_t> v = kmp(str);
            for (size_t k = 0; k < v.size(); k++){
                if(v[k] == s.substr(s.size()-j, j).size()){
                    ans.push_back(s.substr(s.size()-j, j));
                }
            }
        }
    }

    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}