// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

// Note:

// The solution set must not contain duplicate quadruplets.

// Example:

// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n=nums.size();
    vector<vector<int> > set;
    if(n<4) return set;
    sort(nums.begin(),nums.end());
    for(int i=0; i<n-3; i++){
        if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
        for(int j=i+1; j<n-2; j++){
            int left=j+1;
            int right=n-1;
            int sum=target-(nums[i]+nums[j]);
            while(left<right){
                int temp=nums[left]+nums[right];
                if(temp<sum) left++;
                else if(temp>sum) right--;
                else{
                    vector<int> solution(4);
                    solution[0]=nums[i];
                    solution[1]=nums[j];
                    solution[2]=nums[left];
                    solution[3]=nums[right];
                    left++;
                    right--;
                    while(nums[left]==nums[left-1]&&left<right) left++;
                    while(nums[right]==nums[right+1]&&left<right) right--;
                    set.push_back(solution);
                }
            }
            while(j<n-2&&nums[j+1]==nums[j]) j++;
        }
        while(i<n-3&&nums[i+1]==nums[i]) i++;
    }
    return set;
}