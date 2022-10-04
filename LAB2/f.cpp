#include <iostream>
using namespace std;

struct NODE
{
    int index;
    int val;
    NODE * next;
    NODE * prev;
    NODE(int x,int i){
        index = i;
        val = x;
        next = prev = NULL;
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
    void add(int x,int i){
        NODE * n = new NODE(x,i);
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

    void print(int m,int l){
        NODE * cur = head;
        while (cur)
        {
            if (cur->index == l){
                cout << m << " ";
                l = -1e9;
            }
            else{
                cout << cur->val << " ";
                cur = cur -> next;    
            }
            
        }   
    }
};




int main (){
    DLL dll;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        dll.add(x,i);
    }
    int m,l;
    cin >> m >> l;
    dll.print(m,l);

   return 0; 
}