#include <bits/stdc++.h>
using namespace std;
int main () {
    deque <int> b;
    deque <int> n;
    int cnt = 0;
    for (int i = 0; i < 5; i++){
        int x;
        cin >> x;
        b.push_back(x);
    }
    for (int i = 0; i < 5; i++){
        int x;
        cin >> x;
        n.push_back(x);
    }
    while (!b.empty() and !n.empty())
    {
        if ( b.front() > n.front() ){
            if (b.front() == 9 and n.front() == 0){
                n.push_back(b.front());
                n.push_back(n.front());
            }
            else {
                b.push_back(b.front());
                b.push_back(n.front());
            }
        }
        else {
            if (n.front() == 9 and b.front() == 0){
                b.push_back(b.front());
                b.push_back(n.front());
            }

            else {
            n.push_back(b.front());
            n.push_back(n.front());
            }

        }
        b.pop_front();
        n.pop_front();
        cnt++;
        if (cnt == 1000000){
           cout << "blin nichya";
           return 0; 
        }
    }
    if (b.empty()){
        cout << "Nursik " << cnt;
    }
    else{
        cout << "Boris " << cnt;
    }
    return 0;
}