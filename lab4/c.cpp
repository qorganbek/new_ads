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


    node * search(int x){
        return this->search(x,this->root);
    }


    void solve (int x){
        node * n = search(x);
        print(n);
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


    node * search(int x,node * cur){
        if (cur == NULL) return NULL;
        if (cur->val  == x) return cur;
        else if (cur->val > x) return search(x,cur->left);
        else return search(x,cur->right);
    }

    void print(node * cur){
        if (!cur) return;
        cout << cur->val << " ";
        print(cur->left);
        print(cur->right);
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n;
    bst * b = new bst();
    
    for (int i = 0; i < n; i++){
        cin >> x;
        b->add(x);    
    }
    cin >> x;
    b->solve(x);
    return 0;
}