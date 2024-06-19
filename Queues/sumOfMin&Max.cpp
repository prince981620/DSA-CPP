#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int sumOfMaxMin(vector<int>& nums,int k){
    deque<int>dq1,dq2;
    int ans = 0;

    // process first k element for maximum elements and minumun elements
    for(int i=0;i<k;i++){
        // for maximim 
        while(!dq1.empty() && nums[i] >= nums[dq1.back()]){
            dq1.pop_back();
        }
        // for minimum
        while(!dq2.empty() && nums[i] <= nums[dq2.back()]){
            dq2.pop_back();
        }
        dq1.push_back(i);
        dq2.push_back(i);
    }

    ans += nums[dq1.front()] + nums[dq2.front()];

    // process reamaining elements
    for(int i=k;i<nums.size();i++){
        // pop out of index elements for dq1
        if(!dq1.empty() && i-dq1.front() >= k){
            dq1.pop_front();
        }
        // for dq2
        if(!dq2.empty() && i-dq2.front() >= k){
            dq2.pop_front();
        }
        // for maximim remove all smaller 
        while(!dq1.empty() && nums[i] >= nums[dq1.back()]){
            dq1.pop_back();
        }
        // for minimum remove all larger
        while(!dq2.empty() && nums[i] <= nums[dq2.back()]){
            dq2.pop_back();
        }
        dq1.push_back(i);
        dq2.push_back(i);
        ans += nums[dq1.front()] + nums[dq2.front()];
    }
    return ans;
}


int main(){
    vector<int>v{2,5,-1,7,-3,-1,-2};\
    int ans = sumOfMaxMin(v,4);
    cout << ans << endl;
    return 0;
}