// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

// Now consider if some obstacles are added to the grids. How many unique paths would there be?

// Input:
// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// Output: 2
#include <iostream>
#include <vector>
using namespace std;

//dp
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
int m=obstacleGrid.size();
int n=obstacleGrid[0].size();
vector<vector<int> > dp(m, vector<int>(n,1));
if(obstacleGrid[0][0]==1) return 0;
for(int i=1; i<m; i++){
    dp[i][0]=!obstacleGrid[i][0]&&dp[i-1][0];
}
for(int i=1; i<n; i++){
    dp[0][i]=!obstacleGrid[0][i]&&dp[0][i-1];
}
for(int i=1; i<m; i++){
	for(int j=1; j<n; j++){
        dp[i][j]=dp[i-1][j]+dp[i][j-1];
        if(obstacleGrid[i][j]==1) dp[i][j]=0;  
	}
}
return dp[m-1][n-1];
}
