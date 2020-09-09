// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

// Example 1:

// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example 2:

// Input: "cbbd"
// Output: "bb"
// 
#include<iostream>
#include<vector>
using namespace std;


int longestOnLetter(string s, int L, int R){
    int left=L, right=R;
    while(left>=0 && right<s.length()&&s[left]==s[right]){
        left--;
        right++;
    }
    return right-left-1;
}

// 以每个字母为中心向两边扩展求最长回文数
string longestPalindrome(string s) {
    int leftPos=0, rightPos=0;
    int maxLen;
    for(int i=0;i<s.length();i++){
        int mode1=longestOnLetter(s,i,i);
        int mode2=longestOnLetter(s,i,i+1);
        int longerLen=max(mode1,mode2);
        if(longerLen>maxLen){
            leftPos=i-(longerLen-1)/2;
            maxLen=longerLen;
        }
    }
    cout<<leftPos;
    return s.substr(leftPos,maxLen);
}

//dp
string dpPal(string s){
    int len = s.length();
    vector<vector<int> >dp(len,vector<int>(len,0)); 
    int maxLen = 1, start_point=0;
    if(len==1){
        return s;
    }
    if(len==2){
        if(s[0]==s[1]) return s;
        else return s.substr(0,1);
    }
    for(int j=1;j<3;j++){
        int i = 0;
        while(i+j<len){
            if(s[i]==s[i+j]){
                dp[i][i+j]=1;
                if(j>maxLen-1){
                    maxLen=j+1;
                    start_point=i;
                }
            }
            i+=1;
        }
    }
    for(int j=3; j<len; j++){
        int i=0;
        while(i+j<len){
            if(s[i]==s[i+j]&&dp[i+1][i+j-1]){
                dp[i][i+j]=1;
                if(j>maxLen){
                    maxLen=j+1;
                    start_point=i;
                }
            }
            i+=j;
        }
    }
    cout<<dp[1][3]<<maxLen;
    return s.substr(start_point,maxLen);
}

int main(int argc, char const *argv[])
{
    cout<<dpPal("caba");
    return 0;
}