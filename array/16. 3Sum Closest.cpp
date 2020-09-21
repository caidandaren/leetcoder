// Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

 

// Example 1:

// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
// 
int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();
    
    int minDis=abs(target-nums[0]-nums[1]-nums[2]);
    int minData=nums[0]+nums[1]+nums[2];
    sort(nums.begin(),nums.end());
    for(int i=0; i<n-1; i++){
        
        int left=i+1;
        int right=n-1;
    
        while(left<right){
            int temp=nums[left]+nums[right]+nums[i];
            int tempDis=abs(target-temp);
            if(tempDis<minDis){
                minDis=tempDis;
                minData=temp;
                int tempLeft=nums[left], tempRight=nums[right];
                
            }
            if(temp<target) left++;
            else right--;
        }
        cout<<i<<' '<<minDis<<' '<<minData<<endl;
        while(i<n-1&&nums[i+1]==nums[i]) i++;
    }
    return minData;  
}    