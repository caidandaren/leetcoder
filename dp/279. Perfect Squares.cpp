
// Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

// Example 1:

// Input: n = 12
// Output: 3 
// Explanation: 12 = 4 + 4 + 4.
// 
int numSquares(int n) {
    vector<int> dp(n+1, 100000);
    int t=1;
    for(int i=1; i<n+1; i++){
        if(i==t*t){
            t=t+1;
            dp[i]=1;
        }
        else{
            for(int j=1; j<t; j++){
                dp[i] = min(dp[i],dp[j*j]+dp[i-j*j]);
            }
        }
    }
    return dp[n];
}