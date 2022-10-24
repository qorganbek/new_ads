#include <iostream>
using namespace std;
struct node
{
    int val;
    node *right, *left;
    node(int val){
        this->val = val;
        this->left = this->right = NULL;
    }
};

struct bst
{
    private:
        node * root;
            node * add(node * cur, int x){
                if (cur == NULL) cur = new node(x);
                else if (cur->val > x){
                    if (cur->left == NULL) cur->left = add(cur->left,x);
                    else add(cur->left,x);
                }
                else if (cur->val < x){
                    if (cur->right == NULL) cur->right = add(cur->right,x);
                    else add(cur->right,x);
                }
                return cur;             
            }

            void print(node * cur){
                if (cur != NULL){
                    print(cur->left);
                    cout << cur->val << " ";
                    print(cur->right);
                    
                }
            }

    public:
        bst(){
            root = NULL;
        }
        void add(int x){
            node * res = this->add(this->root,x);
            if (root == NULL) root = res;
        }

        void print(){
            print(this->root);
        }
};


int main(){
    int n;
    cin >> n;
    bst * tree = new bst();
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        tree->add(x);
    }
    return 0;
}