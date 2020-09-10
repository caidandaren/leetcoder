// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
#include <iostream>
#include <vector>
using namespace std;

// dp
int maxSubArray(vector<int>& nums) {
	int n=nums.size();
	if(n==0){
		return 0;
	}
	if(n==1){
		return nums[0];
	}
    int dp[n];
    fill(dp,dp+n,0);
    dp[0]=nums[0];
    int max_sum=dp[0];
    for(int i=1; i<n; i++){
    	dp[i]=max(nums[i],nums[i]+dp[i-1]);
    	if(dp[i]>max_sum) max_sum=dp[i];
    }
    return max_sum;
}			

int main(int argc, char const *argv[])
{	
	int a[9]={-2,1,-3,4,-1,2,1,-5,4};
	
	vector<int> t(a,a+9);
	cout<<maxSubArray(t);
	return 0;
}