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

void levelOrderTraverselInRow(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout << endl ;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }

}

void preOderTraversel(Node* root){
    // NLR
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preOderTraversel(root->left);
    preOderTraversel(root->right);
}

void inOrderTraversel(Node* root){
    // LNR
    if(root == NULL){
        return;
    }
    inOrderTraversel(root->left);
    cout << root->data << " ";
    inOrderTraversel(root->right);
}

void postOderTraversel(Node* root){
    // LRN
    if(root == NULL){
        return;
    }
    postOderTraversel(root->left);
    postOderTraversel(root->right);
    cout << root->data << " ";
}

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return max(left,right) + 1;
}

int main(){
    Node* root = NULL;
    root = buildTree();
    levelOrderTraversel(root); 
    cout << endl << "printing row wise traversel" << endl ;
    levelOrderTraverselInRow(root);
    
} 