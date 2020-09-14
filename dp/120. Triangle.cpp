// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

// For example, given the following triangle

// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
// 
#include <iostream>
#include <vector>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
	int n = triangle.size();
    if(n==1) return triangle[0][0];
    vector<vector<int> > dp(n, vector<int>(n,0));
    dp[0][0]=triangle[0][0];
    int maxsum=INT_MAX;
    for(int i=1; i<n; i++){
    	for(int j=0; j<=i; j++){
    		if(j==0) dp[i][j]=dp[i-1][j]+triangle[i][j];
    		else if(j==i) dp[i][j]=dp[i-1][j-1]+triangle[i][j];
    		else dp[i][j]=min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];
    		if(i==n-1){
    			if(maxsum>dp[i][j]){
    				maxsum=dp[i][j];
    			}
    		}
    	}
    }
    return maxsum;
}