// Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You may assume no duplicates in the array.

// Example 1:

// Input: [1,3,5,6], 5
// Output: 2
// 
int searchInsert(vector<int>& nums, int target) {
    int n=nums.size();
    int left=0,right=n-1;
    int mid=(left+right)/2;
    while(nums[mid]!=target&&left<right){
        if(nums[mid]>target) right=mid-1;
        if(nums[mid]<target) left=mid+1;
        mid=(left+right)/2;
    }
    if(nums[mid]==target) return mid;
    else if(nums[left]>target&&left!=0) return left;
    else if(nums[left]>target&&left==0) return 0; 
    else return left+1;
}