#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
Node* insertIntoBST(Node* root, int data){
    if(!root){
        // this is the first node so create a new node
        root = new Node(data);
        return root;
    }
    // otherwise not the first node so we need to either insert into left or right
    if(data < root->data){
        root->left = insertIntoBST(root->left,data);
    }else{
        root->right = insertIntoBST(root->right,data);
    }
    return root;
}
void createBST(Node* &root){
    int data;
    cout << "insert the data for node" << endl;
    cin >> data;
    while(data != -1){
        root = insertIntoBST(root,data);
        cin >> data;
    }
}
void levelOrderTraversel(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* front = q.front(); q.pop();
        if(!front){
            cout << endl ;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout << front->data << " " ;
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
    }
    cout << endl;
}
void preOrderTraversel(Node* root){
    // NLR
    if(!root) return;
    cout << root->data << " ";
    preOrderTraversel(root->left);
    preOrderTraversel(root->right);
}
void inOrderTraversel(Node* root){
    // LNR
    if(!root) return;
    inOrderTraversel(root->left);
    cout << root->data << " ";
    inOrderTraversel(root->right);
}
void postOrderTraversel(Node* root){
    // LRN
    if(!root) return;
    postOrderTraversel(root->left);
    postOrderTraversel(root->right);
    cout << root->data << " ";
}
int main(){
    Node* root = NULL;
    createBST(root);
    cout << "Printing Level Order Traversel" << endl;
    levelOrderTraversel(root);
    cout << endl << "Printing preOrderTraversel" << endl;
    preOrderTraversel(root);
    cout << endl << "Printing inOrderTraversel" << endl;
    inOrderTraversel(root);
    cout << endl << "Printing postOrderTraversel" << endl;
    postOrderTraversel(root);
    return 0;
}
