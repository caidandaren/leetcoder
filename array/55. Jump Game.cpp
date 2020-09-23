// Given an array of non-negative integers, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Determine if you are able to reach the last index.

 

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
// 
bool canJump(vector<int>& nums) {
    int n=nums.size();
    if(n==1) return true;
    int max_t=0;
    for(int i=0; i<n; i++){
        if(i>max_t) break;
        if(i+nums[i]>max_t){
            max_t=i+nums[i];
            if(max_t>=n-1) return true;
        }
    }
    return false;
}