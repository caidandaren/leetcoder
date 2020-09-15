//  Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
//  Input: s = "leetcode", wordDict = ["leet", "code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".

//unfinished
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

// bool wordBreak(string s, vector<string>& wordDict) {
//     int n=s.size();
//     set<string> dict;
//     for(auto w: wordDict)
//     	dict.insert(w);
//     vector<bool> dp(n+1, false);
//     dp[0] = true;
//     for(int i=1; i<n+1; i++){
//     	for(int j=i; j>=0; j--){
//     		string tmp = s.substr(j,i-j+1);
//     		if(dict.find(tmp)!=dict.end())
//     			dp[i+1]=dp[i+1]||dp[j];
//     		if(dp[i+1]) break;
//     	}
//     }
//     return dp[n];

// }

// int main(int argc, char const *argv[])
// {
// 	// wordBreak("leetcode", ["leet", "code"]);
// 	string a = "test";
// 	string str[] = {"test","fuk"};
// 	vector<string> b(str,str+2);
// 	int n=a.size();
//     set<string> dict;
//     for(auto w: str)
//     	dict.insert(w);
// 	cout<<dict.end();

// 	return 0;
// }