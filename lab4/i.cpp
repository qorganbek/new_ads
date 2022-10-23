#include<bits/stdc++.h>
using namespace std;
 
struct node{
    int key;
    int count;
    struct node *left, *right;
};
 
struct node *newNode(int item){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    temp->count = 1;
    return temp;
}
 
void inorder(struct node *root){
    if (root != NULL){
        inorder(root->left);
        cout << root->key << "("
             << root->count << ") ";
        inorder(root->right);
    }
}
 
struct node* insert(struct node* node, int key){

    if (node == NULL) return newNode(key);
 
    if (key == node->key){
        (node->count)++;
        return node;
    }
 
    if (key < node->key) node->left = insert(node->left, key);
    else node->right = insert(node->right, key);
 
    return node;
}

int counter(struct node* node, int key){

    if (node == NULL) return 0;
 
    if (key == node->key){
        return node->count;
    }
 
    if (key < node->key) counter(node->left, key);
    else counter(node->right, key);
}
 
struct node * minValueNode(struct node* node){

    struct node* current = node;
 
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
 
struct node* deleteNode(struct node* root, int key){
    
    if (root == NULL) return root;
 
    if (key < root->key) root->left = deleteNode(root->left, key);
 
    else if (key > root->key) root->right = deleteNode(root->right, key);
 
    else{
        if (root->count > 1){
            (root->count)--;
            return root;
        }
 
        if (root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }else if (root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }
 
        struct node* temp = minValueNode(root->right);
 
        root->key = temp->key;
        root->count = temp->count;
       
          temp->count = 0;
 
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
 
int main(){

    struct node *root = NULL;

    int n; cin >> n;
    string str;
    int num;

    while (n--){
        cin >> str >> num;
        if (str == "insert"){
            root = insert(root, num);
        }else if (str == "delete"){
            root = deleteNode(root, num);
        }else if (str == "cnt"){
            cout << counter(root, num) << endl;
        }
    }
    return 0;
}