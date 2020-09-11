// 'A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

// How many possible unique paths are there?

// Input: m = 3, n = 2
// Output: 3
// Explanation:
// From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Right -> Down
// 2. Right -> Down -> Right
// 3. Down -> Right -> Right

#include <iostream>
#include <vector>
using namespace std;

// dp
int uniquePaths(int m, int n){
	vector<vector<int> > dp(m, vector<int>(n,1));
	for(int i=1; i<m; i++){
		for(int j=1; j<n; j++){
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	return dp[m-1][n-1];
}

int main(int argc, char const *argv[])
{
	/* code */
	cout<<uniquePaths(1,1);
	return 0;
}