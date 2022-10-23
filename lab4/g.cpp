#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

struct bct {
    Node* root;

    bct(){
        root = NULL;
    }

    Node *insert(Node *current, int x){
        if (current == NULL){
            current = new Node(x);
            return current;
        }
        if (x > current->data) current->right = insert(current->right, x);
        else if (x < current->data) current->left = insert(current->left, x);
        return current;
    }

    void *print(Node * current){
        if (current != NULL){
            print(current->left);
            cout << current->data << " ";
            print(current->right);
        }
    }

    int height(Node *node){
        if (!node)
            return 0;
    
        int h_l = height(node->left);
        int h_r = height(node->right);
    
        return max(h_l, h_r) + 1;
    }

    void calculateSum(Node* node, int level, int sum[]){
        if (node == NULL)
            return;

        sum[level] += node->data;
    
        calculateSum(node->left, level + 1, sum);
        calculateSum(node->right, level + 1, sum);
    }

    bool check(Node *current, string str){
        for (int i = 0; i < str.size(); i++){
            if (str[i] == 'L'){
                if (current->left == NULL) return false;
                else current = current->left;
            }else{
                if (current->right == NULL) return false;
                else current = current->right;
            }
        }
        return true;
    }

    int diameter(Node * current){ 
     if (current == 0) return 0; 
     int lheight = height(current->left); 
     int rheight = height(current->right);
     int ldiameter = diameter(current->left); 
     int rdiameter = diameter(current->right); 
     return max(lheight + rheight + 1, max(ldiameter,rdiameter));
 } 

};


int main(){
    bct bctt;
    int n; cin >> n;
    int num;
    for (int i = 0; i < n; i++){
        cin >> num;
        bctt.root = bctt.insert(bctt.root, num);
    }
    cout << bctt.diameter(bctt.root);
}