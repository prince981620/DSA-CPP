#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
// ctor
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
Node* buildTree(){
    int data;
    cout << "enter the Data : ";
    cin >> data;

    if(data == -1){
        return NULL;
    }
    Node* root = new Node(data);
    cout << "Enter data for left part of " << data << " node : " << endl;
    root->left = buildTree();
    cout << "Enter data for right part of " << data << "node : " << endl;
    root->right = buildTree();

    return root;
}
void levelOrderTraversel(Node* root){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}
int main(){
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversel(root); 
    
}