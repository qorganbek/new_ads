#include <iostream>
#include <map>

using namespace std;

int main (){
    map <int,int> mp;
    mp.insert({5,7});
    mp.insert({7,9});
    mp.insert({11,13});
    mp.insert({13,15});

    auto it = mp.find(7);
    mp.erase(it);
    map<int,int>::iterator iter;
    for (iter = mp.begin(); iter != mp.end(); iter++){
        cout << iter->first << " " << iter->second << endl;
    }

    return 0;
}