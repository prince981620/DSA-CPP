#include <iostream>
using namespace std;

class KQueues {
    public:
    int n,k,freeSpot;
    int *arr, *front, *rear, *next;
     KQueues(int _n, int _k):n(_n),k(_k),freeSpot(0){
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];

        for(int i=0;i<k;i++){
            front[i]=rear[i]=-1;
        }

        for(int i=0;i<n;i++){
            next[i]=i+1;
        }
        next[n-1]=-1;
     }
    //  push x into qth Queue

    bool push(int x,int qi){
        // check for overflow
        if(freeSpot == -1){
            return false;
        }else{
            // find free index
            int index = freeSpot;

            // update freeSpot
            freeSpot = next[index];

            // if this is the first element in qi
            if(front[qi]==-1){
                front[qi] = index;
            }else{
                // link new element to Qi's rearest element
                next[rear[qi]] = index;
            }
            // update next
            next[index] = -1;
            // update rear
            rear[qi] = index;
            // push element into arr
            arr[index] = x;
            return true;
        }
    }
    int pop(int qi){
        // check for underflow
        if(front[qi]==-1){
            return -1;
        }else{
            // find index
            int index = front[qi];

            // update front 
            front[qi] = next[index];

            // since this next became front now this will point to free spot
            next[index]= freeSpot;
            // update freeSpot
            freeSpot = index;
            return arr[index];
        }
    }

    ~KQueues(){
        delete[] arr;
        delete[] next;
        delete[] front;
        delete[] rear;
    }

};
int main() {
  KQueues kq(8,3);
  cout << kq.push(1,0) << endl;
  cout << kq.push(2,0) << endl;
  cout << kq.push(5,1) << endl;
  cout << kq.push(3,0) << endl;
  cout << kq.pop(1) << endl;
  cout << kq.pop(1) << endl;
  cout << kq.pop(0) << endl;
  cout << kq.pop(0) << endl;
  cout << kq.pop(0) << endl;
  cout << kq.pop(0) << endl;

  return 0;
} 