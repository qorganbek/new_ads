#include <iostream>

using namespace std;

struct node{
    int val;
    node * left;
    node * right;
    int cnt;
    node(int val){
        this->val = val;
        this->left = this->right = NULL;
    }
};

struct bst{
    public:
    bst(){
        root = NULL;
    }
    void add(int x){
        node * result = this->add(this->root, x);
        if(root == NULL){
            root = result;
        }
    }
    void print(){
        this->print(this->root);
    }

    int check(int s){
        return this->check(root,s);
    }

    int _get_size(){
        return this->_get_size(this->root);
    }

    private:
    node * root;
    node * add(node * current, int x){
        if(current == NULL){
            current = new node(x);
        }else if(current->val > x){
            if(current->left == NULL){
                current->left = add(current->left, x);
            }else{
                add(current->left, x);
            }
        }else if(current->val < x){
            if(current->right == NULL){
                current->right = add(current->right, x);
            }else{
                add(current->right, x);
            }
        }
        return current;
    }
    void print(node * current){
        if(current != NULL){
            print(current->left);
            cout << current->val << " ";
            print(current->right);
        }
    }

    int _get_size(node * cur){
        if (cur == NULL) return 0;
        return _get_size(cur->left) + _get_size(cur->right) + 1;
    }

    int check(node * cur, int s){
        if (cur == NULL) return -1;
        if (cur->val == s) return _get_size(cur);
        else if (cur->val > s) return check(cur->left,s);
        else if (cur->val < s) return check(cur->right,s);
    }
};


int main(){
    int n, x;
    cin >> n;
    bst * b = new bst();
    
    for (int i = 0; i < n; i++){
        cin >> x;
        b->add(x);    
    }
    cin >> x;
    cout << b->check(x);

    return 0;
}