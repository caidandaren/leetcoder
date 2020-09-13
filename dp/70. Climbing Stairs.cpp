// You are climbing a stair case. It takes n steps to reach to the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
// Input: 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps


 int climbStairs(int n) 
{  
        if(n==1) return 1;
        else if(n==2) return 2;
        else if(n==0) return 0;
        else{
        vector<int> count(n + 1);
        count[0] = 0;
        count[1] = 1;
        count[2] = 2;
        for (int i = 3; i <= n; ++i) {
            count[i] = count[i - 1] + count[i - 2];
        }
        return count[n];
        }
}