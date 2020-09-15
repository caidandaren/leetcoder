// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
// Input: 

// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0

// Output: 4
#include<iostream>
#include<vector>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();
	int pre;
	vector<int> cur(n,0);
    int min_s=0;
    for(int i=0; i<m; i++){
    	for(int j=0; i<n; j++){
    		int temp = cur[j];
    		if(!i || !j || matrix[i][j]=='0'){
    			cur[j] = matrix[i][j]-'0';
    		}
    		else{
    			cur[j] = min(pre, cur[j], cur[j - 1]) + 1;
    		}
    		min_s=max(min_s, cur[j]);
    		pre=temp;
    	}
    }
    return min_s*min_s;}

int main(int argc, char const *argv[])
{
	cout<<max(1,2);
	return 0;
}