#include <iostream>
using namespace std;

class Heap{
    public:
    int arr[69];
    int size;

    Heap() {
        size = 0;
    }
    
    void insert(int data){
        // insert the value at the end
        size += 1;
        int index = size;
        arr[index] = data;

        // move it to its correct place
        while(index >1){
            int parentIndex = index/2;
            if(arr[index]>arr[parentIndex]){
                swap(arr[index],arr[parentIndex]);
                index = parentIndex;
            }else{
                break;
            }
            
        }
    }

    void remove(){
        // replace root node with last node data
        arr[1] = arr[size];
        size--;
        // place root node ka data at its poper place
        int index = 1;
        while(index < size) {
            int leftIndex = 2*index;
            int rightIndex = 2*index+1;

            int largestIndex = index;
            if(leftIndex < size && arr[leftIndex] > arr[largestIndex]){
                largestIndex = leftIndex;
            }
            if(rightIndex < size && arr[rightIndex] > arr[largestIndex]){
                largestIndex = rightIndex;
            }
            if(largestIndex == index){
                // node is already at correct position
                break;
            }else{
                swap(arr[index],arr[largestIndex]);
                index = largestIndex;
            }
        }
        
    }



};
int main(){
    Heap h;
    // h.arr[0] = -1;
    // h.arr[1] = 100;
    // h.arr[2] = 50;
    // h.arr[3] = 60;
    // h.arr[4] = 44;
    // h.arr[5] = 45;
    // h.size = 5;

    h.insert(50);
    h.insert(30);
    h.insert(70);
    h.insert(40);
    h.insert(80);
    h.insert(100);

    cout << "Printing the Heap" << endl;
    for(int i=0;i<=h.size;i++){
        cout << h.arr[i] << " " ;
    }
    cout << endl;

    h.remove();

    cout << "Printing the Heap" << endl;
    for(int i=0;i<=h.size;i++){
        cout << h.arr[i] << " " ;
    }
    cout << endl;
}