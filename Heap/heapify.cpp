#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i){
    int index = i;
    int leftIndex = 2*i;
    int rightIndex = 2*i+1;

    int largestIndex = index;
    if(leftIndex <= n && arr[leftIndex] > arr[largestIndex]){
        largestIndex = leftIndex;
    }
    if(rightIndex <= n && arr[rightIndex] > arr[largestIndex]){
        largestIndex = rightIndex;
    }
    if(largestIndex != index){
        // either left or right is larger
        swap(arr[index],arr[largestIndex]);
        index = largestIndex;
        heapify(arr,n,index);
    }
}

void BuildHeap(int arr[],int n){
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
}

void heapSort(int arr[],int n){
    int index = n;
    while(n!=1){
        swap(arr[1],arr[index]);
        index--;
        n--;

        // heapify the first element
        heapify(arr,n,1);
    }
}

int main(){
    int arr[] = {-1,12,15,13,11,14};
    int n = 5;
    BuildHeap(arr,n);
    

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr,n);

    for(int i=1;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}