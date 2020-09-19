// Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

// Example:

// nums = [1, 2, 3]
// target = 4

// The possible combination ways are:
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)

// Note that different sequences are counted as different combinations.

// Therefore the output is 7.
// 
int combinationSum4(vector<int>& nums, int target) {
    int n=nums.size();
    vector<unsigned int> dp(target+1, 0);
    dp[0]=1;
    for(int i=0; i<target; i++){
        for(int j=0; j<n; j++){
            if((i+nums[j])<=target){
                dp[i+nums[j]]+=dp[i];                  
            }              
        }
        if(i==333) cout<<dp[39];
    }
    return dp[target];
}