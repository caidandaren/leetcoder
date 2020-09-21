// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

// Notice that the solution set must not contain duplicate triplets.

 

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// 
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int> > res;
    if(n<3) return res;
    sort(nums.begin(),nums.end());
    for(int i=0; i<n-1; i++){
        
        int left=i+1;
        int right=n-1;
        int sum=-nums[i];
        while(left<right){
            int temp=nums[left]+nums[right];
            if(temp>sum) right--;
            else if(temp<sum) left++;
            else{
                vector<int> triplet(3);
                triplet[0]=nums[i];
                triplet[1]=nums[left];
                triplet[2]=nums[right];
                res.push_back(triplet);
                
                while(left<right && nums[left]==triplet[1]) left++;
                while(left<right && nums[right]==triplet[2]) right--;
            }
        }
        while(i<n-1&&nums[i+1]==nums[i]) i++;
    }
    return res;  
}