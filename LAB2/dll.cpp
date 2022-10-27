#include <iostream>

using namespace std;


struct node{
    int val;
    node *next, *prev;
    node(int x){
        val = x;
        next = prev = NULL;
    }
};


struct dll
{
    node * head;
    node * tail;
    dll(){
        head = tail = NULL;
    }
    void add(int x){
        node * n = new node(x);
        if (head == NULL){
            head = n;
            tail = n;
        }
        else{
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
    }


    void delete(int p){
        node * cur = head;
        if (p == 0){
            head = cur->next;
            free(cur);
        }
        else {
            for (int i = 0; i < p-1; i++){
                cur = cur->next;
            }
            cur->next->prev
            cur->prev->next = cur->next;

        }
    }
};


int main (){
    int n, m;
    cin >> n >> m;
    dll _dll;
    for (int i = 0; i < n; i++){
        int s;
        cin >> s;
        _dll.add(s);
    }


    _dll.print();
    return 0;
}