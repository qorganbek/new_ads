#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node * next;

    node(int x){
        val = x;
        next = NULL;
    }
};

int MMM(node *head, int k){
    int mn = INT_MAX, ind = 0, i = 0;
    node * cur = head;
    while(cur){
        if(mn > abs(k-cur->val)){mn = abs(k-cur->val); ind = i;}
        cur = cur->next;
        i++;
    }

    return mn;
}

int main(){
    int n;cin >> n;
    node *head, *cur;
    int k;
    for(int i = 0; i < n; i++){
        int x;cin >> x;
        if(i == 0){
            head = new node(x);
            cur = head;
        }else{
            cur->next = new node(x);
            cur = cur->next;
        }
    }
    cin >> k;

    cout << MMM(head, k);

    return 0;
}