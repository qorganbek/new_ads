#include <iostream>

using namespace std;

struct node
{
    int val;
    node *next, *prev;
    node(int x){
        val = x;
        next = prev = NULL;
    } 
};

struct dll
{
    node *head, *tail;
    dll(){
        head = tail = NULL;
    }


    void add(int x){
        node * n = new node(x);
        if (head == NULL){
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
        node * cur = head;
        while (cur)
        {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    void rprint(){
        node * cur = tail;
        while (cur)
        {
            cout << cur->val << " ";
            cur = cur->prev;
        }
        cout << endl;  
    }

    void del(int p){
        node * tmp1 = head;
        if (p == 0){
            head = tmp1->next;
            free(tmp1);
        }
        else {
            for (int i = 0; i < p-1; i++){
                tmp1 = tmp1->next;
            }
            node * tmp2 =   ->next;
            tmp1->next = tmp2->next;
            free(tmp2);
        }
    }
    


    void insert(int p, int x){
        if (p == 0){
            node * n = new node(x);
            n->next = head;
            n = head;
        }
        else {
            node * cur = head;
            while (--p > 0)
            {
                cur = cur->next;
            }
            node * n = new node(x);
            n->next = cur->next;
            cur->next = n;
        }
    }
};



int main (){
    dll _dll;
    int n,x;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        _dll.add(x);
    }
    // cin >> x;
    // _dll.del(x);
    _dll.insert(0,-39);
    _dll.print();

    return 0;
}