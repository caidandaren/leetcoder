// Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
#include <iostream>
#include <vector>
using namespace std;


int maxProduct(vector<int>& nums) {
	int n = nums.size();
    int max_p=nums[0], max_n=nums[0];
    int maxint=nums[0];
    for(int i=0; i<n; i++){
    	if(nums[i]<0) swap(max_p,max_n);
    	max_p = max(max_p*nums[i],nums[i]);
    	max_n = min(max_n*nums[i],nums[i]);
    	maxint = max(maxint, max_p);
    }

    return maxint;
}

int main(int argc, char const *argv[])
{
	int tmp[4]={2,3,-2,4};
	vector<int> test(tmp,tmp+4);
	cout<<maxProduct(test);
	return 0;
}