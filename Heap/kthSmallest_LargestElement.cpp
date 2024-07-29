#include<iostream>
#include <queue>
using namespace std;

int getKthSmallestElement(int arr[],int n,int k){
    // normal methos 1-> sort and return k-1 th element
    // methtode 2 -> push into minheap pop k-1 element and return top
    // using maxheap takes less space
    priority_queue<int>pq;
    // push 1st k element into pq
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    // for remaining elements push only if element is smaller than top
    for(int i=k;i<n;i++){
        int element = arr[i];
        if(element < pq.top()){
            pq.pop();
            pq.push(element);
        }
    }
    return pq.top();
}
int getKthLargestELement(int arr[],int n, int k){
    priority_queue<int, vector<int>, greater<int> >minpq;
    // push first kth element into min heap
    for(int i=0;i<k;i++){
        minpq.push(arr[i]);
    }
    // for remaining push only if the element are larger than top
    for(int i=k;i<n;i++){
        int element = arr[i];
        if(element > minpq.top()){
            minpq.pop();
            minpq.push(element);
        }
    }
    return minpq.top();
}
int main(){
    int arr[] = {3,5,4,6,9,8,7};
    int n = 7;
    int k = 1;
    cout << k << "th smallest element is : " << getKthSmallestElement(arr,n,k);
    cout << endl;
    cout << k << "th largest element is : " << getKthLargestELement(arr,n,k);
    cout << endl;

}