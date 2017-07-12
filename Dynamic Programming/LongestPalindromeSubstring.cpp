/*
Problem Statement-
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        bool dp[n][n];
        memset(dp,false,sizeof(dp));
        int maxLen=1;
        //Making true for length of 1
        for(int i=0;i<n;i++)
            dp[i][i]=true;
        int start=0;
        //chacking and making true for length of 2
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
                maxLen=2;
                start=i;
            }
        }
        //Now taking care for length greater than 2
        for(int k=3;k<=n;k++){   //k means length of substring
            for(int i=0;i<n-k+1;i++){ //i means starting point of substring
                int j=i+k-1;    //j means ending point of substring
                if(dp[i+1][j-1] && s[i]==s[j]){
                    dp[i][j]=true;
                    if(k>maxLen){
                        maxLen=k;
                        start=i;                        
                    }
                }
            }
        }
        string result=s.substr(start,maxLen);
        return result;
    }
};
