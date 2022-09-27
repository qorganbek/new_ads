#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node * next;
    node(int x){
        val = x;
        next = NULL;
    }
};

struct ll
{
    node * head;
    node * tail;
    ll(){
        head = NULL;
        tail = NULL;
    }
    void add(int x){
        node * n = new node(x);
        if (head == NULL){
            head = n;
            tail = n;
        }
        else {
            tail -> next = n;
            tail = n;
        }
    }
    void print(){
        node * current = head;
        while (current != NULL)
        {
            cout << current->val << " ";
            current = current->next;
        }
    }
};




int main () {
    int n;
    cin >> n;
    ll l;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        l.add(x);
    }
    int m;
    cin >> m;

    return 0;
}