// Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

// Note: You may not slant the container and n is at least 2.

// Input: [1,8,6,2,5,4,8,3,7]
// Output: 49

#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
    int n=height.size();
    int maxArea=min(height[0],height[n-1])*(n-1);
    int left=0, right=n-1;
    while(left!=right){
        if(maxArea<(right-left)*min(height[left],height[right])){
            maxArea=(right-left)*min(height[left],height[right]);
        }
        if(height[left]<height[right]) left++;
        else right--;
    }
    return maxArea;
}