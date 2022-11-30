#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

void print(queue<int> q, unordered_map<int,int> mp){
    while (q.size() > 0){
        int current = q.front();
        q.pop();
        cout << current << " ";
        if(mp[current] == 0) continue;
        q.push(mp[current]);
    }
    cout << endl;
}



int main(){


    int i = 1; 
    while (i != 7)
    {
        bool first = true;
        unordered_map<int, int> um;
        queue<int> q;
        for(int j = 1; j <= 6; j++){
            if(i == j){
                continue;
            }
            else um[j] = j+1; 
        }
        i++;
    }
    return 0;
}