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
Node* sortedArrayToBST(int arr[],int s,int e){
    if(s>e) return NULL;
    int mid = (s+e)/2;

    int data = arr[mid];
    Node* root = new Node(data);
    root->left = sortedArrayToBST(arr,s,mid-1);
    root->right = sortedArrayToBST(arr,mid+1,e);
    return root;
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

void convertIntoSortedDLL(Node* root,Node* &head){
    if(!root) return;

    // right subtree into LL
    convertIntoSortedDLL(root->right,head);
    // attack right
    root->right = head;
    if(head){
         head->left = root;
    }
    // update head
    head = root;
    // left subtree into LL
    convertIntoSortedDLL(root->left,head);
}
void printLinkedList(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
}
Node* convertSortedDLLtoBST(Node* &head,int n){
    if(n<=0 || head == NULL) return NULL;
    Node* leftSubtree = convertSortedDLLtoBST(head,n-1-n/2);
    Node* root = head;
    root->left = leftSubtree;
    head = head->right;

    root->right = convertSortedDLLtoBST(head,n/2);
    return root;
}
int main() {
    int inorder[] = {1,2,3,4,5,6,7,8,9};
    int s = 0;
    int e = 8;
    Node* root = sortedArrayToBST(inorder,s,e);
    levelOrderTraversel(root);
    cout << "printing sorted DLL"<< endl;
    Node* head = NULL;
    convertIntoSortedDLL(root,head);
    printLinkedList(head);
    Node* BST = convertSortedDLLtoBST(head,9);
    levelOrderTraversel(BST);

}