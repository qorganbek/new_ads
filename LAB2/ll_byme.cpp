#include <iostream>
using namespace std;



struct node
{
    int val;
    node * next;
    node (int x){
        val = x;
        next = NULL;
    }
    void print(){
        cout << val << " ";
    }
};



int main (){
    node n1(23);
    node n2(16);
    node n3(7);
    node n4(15);
    node n5(27);
    node n6(9);
    node n7(19);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;


    node * current = &n1;

    while (current != NULL)
    {
        cout << current -> val << " ";
        current = current -> next;
    }
    

    return 0;
}