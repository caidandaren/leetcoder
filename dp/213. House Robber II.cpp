// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
// 
// Input: [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
//              because they are adjacent houses.
//              
 int rob(vector<int>& nums) {
    int n = nums.size();
	if(n==0) return 0;
	if(n==1) return nums[0];
    if(n==2) return max(nums[0],nums[1]);
    if(n==3) return max(nums[0],max(nums[2],nums[1]));
    vector<int> dp1(n, 0), dp2(n,0);
    dp1[0]=nums[0];
    dp2[1]=nums[1];
    dp1[1]=nums[1];
    dp2[2]=nums[2];
    dp1[2]=nums[0]+nums[2];
    for(int i=3; i<n; i++){
    	dp1[i]=max(dp1[i-2],dp1[i-3])+nums[i];
        dp2[i]=max(dp2[i-2],dp2[i-3])+nums[i];
    }
    cout<<dp1[2]<<dp2[3];
    return(max(max(dp2[n-2],dp2[n-1]),max(dp1[n-3],dp1[n-2])));
}