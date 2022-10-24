#include <iostream>
using namespace std;
int cnt = 0;
struct node
{
    int val;
    node *right, *left;
    node(int val){
        this->val = val;
        this->left = this->right = NULL;
    }
};
int sum = 0;
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
            }

            void print(node * cur){
                
                if (cur != NULL){
                    print(cur->right);
                    sum += cur->val;
                    cout << sum << " ";
                    print(cur->left);
                    
                    
                }
            }

            void print_mini_triangle(node * cur){
                if (cur != NULL){
                    print_mini_triangle(cur->right);
                    if (cur->left != NULL and cur->right != NULL ) cnt++;
                    
                    print_mini_triangle(cur->left);
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
            this->print(this->root);
        }

        void print_mini_triangle(){
            this->print_mini_triangle(this->root);
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
    tree->print();
    return 0;
}