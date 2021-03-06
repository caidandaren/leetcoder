// Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

// Note:

// Each of the array element will not exceed 100.
// The array size will not exceed 200.
 

// Example 1:

// Input: [1, 5, 11, 5]

// Output: true

// Explanation: The array can be partitioned as [1, 5, 5] and [11].
// 
#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return false;
    int sum=0;
    for(int i=0; i<n; i++) sum+=nums[i];
    if(sum%2!=0) return false;
    sum/=2;
    sort(nums.rbegin(),nums.rend());
    return subsum(nums, sum, 0);
}

bool subsum(vector<int>& nums, int sum, int index){
    int n=nums.size();
    if(index>=n) return false;
    if(sum==nums[index]) return true;
    if(sum<nums[index]) return false;
    return subsum(nums,sum-nums[index],index+1) || subsum(nums,sum,index+1);
    
}