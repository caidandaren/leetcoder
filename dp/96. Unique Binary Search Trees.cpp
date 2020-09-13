// Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
// Input: 3
// Output: 5
// Explanation:
// Given n = 3, there are a total of 5 unique BST's:

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3
//    
int numTrees(int n) {
    if(n==0 || n==1||n==2) return n;
    int dp[n+1];
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3; i<=n; i++){
        dp[i]=0;
        for(int j=0; j<i; j++){
            dp[i]+=dp[j]*dp[i-j-1];
        }
    }
    return dp[n];
}