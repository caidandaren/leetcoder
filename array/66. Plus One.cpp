// Given a non-empty array of digits representing a non-negative integer, increment one to the integer.

// The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.

// You may assume the integer does not contain any leading zero, except the number 0 itself.

 

// Example 1:

// Input: digits = [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
// 
vector<int> plusOne(vector<int>& digits) {
    int n=digits.size();
    if(digits[n-1]==9){
        int temp=0;
        while(digits[n-1-temp]==9&&temp<n-1){
            digits[n-1-temp]=0;
            temp++;
        }
        if(temp!=n-1) digits[n-1-temp]++;
        else if(digits[0]!=9) digits[0]++;
        else{
            digits[0]=1;
            digits.push_back(0);
        }
        
    }
    else digits[n-1]++;
    return digits;
}