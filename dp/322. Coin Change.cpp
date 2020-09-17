// You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// Example 1:

// Input: coins = [1, 2, 5], amount = 11
// Output: 3 
// Explanation: 11 = 5 + 5 + 1

int coinChange(vector<int>& coins, int amount) {
    if(amount==0) return 0;
    int n = coins.size();
    
    vector<int> dp(amount+1,-1);
    dp[0]=0;
    for(int j=0; j<n; j++){
        if(amount>coins[j])
            dp[coins[j]]=1;
    }
    for(int i=1; i<=amount; i++){
        for(int j=0; j<n; j++)
        {
            if(i>=coins[j]){
                if(dp[i-coins[j]]!=-1&&dp[i]!=-1)
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
                else if(dp[i-coins[j]]!=-1&&dp[i]==-1)
                    dp[i]=dp[i-coins[j]]+1;
            }
        }
    }
    return dp[amount];
}