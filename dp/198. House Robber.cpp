// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//              Total amount you can rob = 1 + 3 = 4.
#include<iostream>
#include <vector>
using namespace std;
int rob(vector<int>& nums) {
    int n = nums.size();
	if(n==0) return 0;
	if(n==1) return nums[0];
    if(n==2) return max(nums[0],nums[1]);
    if(n==3) return max(nums[0]+nums[2],nums[1]);
    vector<int> dp(n, 0);
    dp[0]=nums[0];
    dp[1]=nums[1];
    dp[2]=nums[0]+nums[2];
    for(int i=3; i<n; i++){
    	dp[i]=max(dp[i-2],dp[i-3])+nums[i];
    }
    return(max(dp[n-1],dp[n-2]));
 }

int rob(vector<int>& nums) {
	int a=0;
	int b=0;
	int n = nums.size();
	for(int i =0; i<n; i++){
		if(i%2==0){
			a=max(a+num[i],b);
		}
		else{
			b=max(b+num[i],a);
		}
	}
	return(max(a,b))
}