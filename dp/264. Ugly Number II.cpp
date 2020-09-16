// Write a program to find the n-th ugly number.

// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

// Example:

// Input: n = 10
// Output: 12
// Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
// 
int nthUglyNumber(int n) {
    if(n==1) return 1;
    vector<int> dp(n,0);
    dp[0]=1;
    int v2=0, v3=0, v5=0;
    for(int i=1; i<n; i++){
        dp[i]=min(dp[v2]*2,min(dp[v3]*3, dp[v5]*5));
        if(dp[i] == dp[v2]*2) v2++;
        if(dp[i] == dp[v3]*3) v3++;
        if(dp[i] == dp[v5]*5) v5++;
    }
    return dp[n-1];
}