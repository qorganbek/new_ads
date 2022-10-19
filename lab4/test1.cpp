#include <iostream>
using namespace std;

struct node
{
    int val;
    node *left,*right;
    node(int val){
        this->val = val;
        this->left = this->right = NULL;
    }
};


struct bst
{
    node * root;
    bst(){
        root = NULL;
    }
    node * add(node * cur, int x){
        if (cur == NULL){
            cur = new node(x);
        }
        else if (cur->val > x){
            if (cur->left == NULL){
                cur->left = add(cur->left,x);
            }
            else add(cur->left,x);
        }
        else if (cur->val < x){
            if (cur->right == NULL){
                cur->right = add(cur->right,x);
            }
            else add(cur->right,x);
        }
        return cur;
    }
    void print (node * cur){
        if (cur != NULL){
            print(cur->left);
            cout << cur->val << " ";
            print(cur->right);
        }
    }
};




int main (){
    int a[] = {10, 11, 8, 5, 4, 12};
    int n = sizeof(a) / sizeof(int);

    bst * b = new bst();

    for(int i = 0; i < n; ++i){
        b->root = b->add(b->root,a[i]);
    }

    b->print(b->root);
    return 0;
}