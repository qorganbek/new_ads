#include <bits/stdc++.h>
using namespace std;

struct NODE
{
    int sum = 0;
    string val;
    NODE * next;
    NODE * prev;
    NODE(string x){
        val = x;
        prev = next = NULL;
    }
};

void print(NODE * tail){
    NODE * cur = tail;
    while (cur)
    {
        cout << cur->val << endl;
        cur = cur->prev;
    }
    
}


void rm_duplicate(NODE * head){
    
}

int get_cnt(NODE * head){
    int cnt = 0;
    NODE * cur = head;
    while (cur)
    {
        cnt++;
        cur = cur->next;
    }
    return cnt;
}


int main () {
    int n;
    cin >> n;
    NODE * head;
    NODE * tail;
    for (int i = 0; i < n; i++){
        string x;
        cin >> x;
        NODE * n = new NODE(x);
        if (i == 0){
            head = tail = n;
        }
        else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }


    cout << "All in all: "<< get_cnt(head) << endl;
    cout <<"Students:" << endl;
    print(tail);
}