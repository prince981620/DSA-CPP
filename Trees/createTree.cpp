// creating tree using in-order and pre-order traversel
#include <iostream>
#include <queue>
#include <unordered_map>
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
int findPos(int inorder[],int size,int element){
    for(int i=0;i<=size;i++){
        if(inorder[i] == element){
            return i;
        }
    }
    return -1;
}
Node* buildTreeUsingPre_In(int preorder[],int inorder[],int size,int inStIndex,int inEndIndex,int& preIndex,unordered_map<int,int>&mapping){
    // base case 
    if(preIndex >= size || inStIndex > inEndIndex) return NULL;
    // one case soln
    int element = preorder[preIndex++];
    Node* root = new Node(element);
    // find the possition of root node in inOrder

    // int position = findPos(inorder,size,element);

    int position = mapping[element];

    // rest recurssion will handle
    root->left = buildTreeUsingPre_In(preorder,inorder,size,inStIndex,position-1,preIndex,mapping);
    root->right = buildTreeUsingPre_In(preorder,inorder,size,position+1,inEndIndex,preIndex,mapping);
    
    return root;
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
void createMapping(unordered_map<int,int>&mapping,int inorder[],int size){
    for(int i=0;i<size;i++){
        mapping[inorder[i]] = i;
    }
}
 int main(){
    int inorder[]= {3,1,4,5,2};
    int preorder[]= {5,1,3,4,2};
    int size = 5;
    int inStIndex = 0;
    int inEndIndex = size -1;
    int preIndex = 0;
    unordered_map<int,int>mapping;
    createMapping(mapping,inorder,size);
    Node* root = buildTreeUsingPre_In(preorder,inorder,size,inStIndex,inEndIndex,preIndex,mapping);
    levelOrderTraverselInRow(root);
 }