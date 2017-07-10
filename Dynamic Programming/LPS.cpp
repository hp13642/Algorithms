/*
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
*/

class Solution {
public:
    int longestPalindromeSubseqDP(string s,string t){
        int l=s.length();
        int dp[l+1][l+1];
        for(int i=0;i<=l;i++){
            for(int j=0;j<=l;j++){
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(s[i-1]==t[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[l][l];
    }
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int l=s.length();
        if(l==0 || l==1)
            return l;
        else
            return longestPalindromeSubseqDP(s,t);
    }
};
