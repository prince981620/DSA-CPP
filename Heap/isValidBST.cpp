#include <iostream>
using namespace std;

class Info{
    pubic:
        int maxVal;
        bool isHeap;
        
        // ctor
        Info(){
                this->maxVal = NULL;
                this->isHeap = NULL;
        }
        
        Info(int a,bool b){
            this->maxVal = a;
            this->isHeap = b;
        }

};

Info checkValidMaxHeap(head* root){
    //base case
    if(root == NULL){ //NULL
        Info temp;
        temp.maxVal = INT_MIN;
        temp.isHeap = true;
        return temp;
    }
    if(root->left == NULL && root->right == NULL){
        Info temp;
        temp.maxVal = root->data;
        temp.isHeap = true;
        return temp;
    }
    Info leftAns = checkValidMaxHeap(root->left);
    Info rightAns = checkValidMaxHeap(root->right;

    if(leftAns.isHeap && rightAns.isHeap && root->data > leftAns.maxVal && root->data > rightAns.maxVal){
        Info ans;
        ans.maxVal = root->data;
        ans.isHeap = true;
        return ans;
    }else {
        Info ans;
        ans.maxVal = max(root->data,max(leftAns.maxVal,rightAns.maxVal));
        ans.isHeap = false;
        return ans;
    }
}

int main(){

}