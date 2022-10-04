#include <bits/stdc++.h>
using namespace std;

struct NODE
{
    string val;
    NODE * next;
    NODE * prev;
    NODE(string x){
        val = x;
        prev = next = NULL;
    }
};

struct DLL
{
    NODE * head;
    NODE * tail;
    DLL(){
        head = NULL;
        tail = NULL;
    }

    void add(string x){
        NODE * n = new NODE(x);
        if(head == NULL){
            head = n;
            tail = n;
        }
        else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    void print(){
        NODE * cur = tail;
        while (cur)
        {
            cout << cur->val << endl;
            cur = cur->prev; 
        }
    }
};



int main () {
    DLL dll;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        string x;
        cin >> x;
        dll.add(x);
    }
    DLL ans;
    int cnt = 0;
    NODE * cur = dll.head;    
    while (cur)
    {
        NODE * ans_cur = ans.head;
        if (ans_cur == NULL){
            ans.add(cur->val);
            cnt++;
        }
        else {
            int str = 0;
            while (ans_cur)
            {
                if (cur->val == ans_cur->val){
                    str++;
                }
                ans_cur = ans_cur->next;
            }
            if (str == 0){
                    ans.add(cur->val);
                    cnt++;
                }
        }
        cur = cur->next;
    }
    
    
    cout << "All in all: "<< cnt << endl;
    cout <<"Students:" << endl;
    ans.print();
}