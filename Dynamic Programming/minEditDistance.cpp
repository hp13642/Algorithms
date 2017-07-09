/*
Problem Statement-
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. 
(each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

class Solution {
public:
    int minDistanceDP(string &word1,int n,string &word2,int m){
        // If first string is empty, the only option is to
        // insert all characters of second string into first
        if(m==0)
            return n;
        // If second string is empty, the only option is to
        // remove all characters of first string
        if(n==0)
            return m;
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                // If first string is empty, only option is to
                // isnert all characters of second string
                if(i==0)
                    dp[i][j]=j;
                // If second string is empty, only option is to
                // remove all characters of second string
                else if(j==0)
                    dp[i][j]=i;
                else{
                    // If last characters are same, ignore last char
                    // and recur for remaining string
                    if(word1[i-1]==word2[j-1])
                        dp[i][j]=dp[i-1][j-1];
                    // If last character are different, consider all
                    // possibilities and find minimum
                    else
                        dp[i][j]=1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])); //dp[i][j-1]-> INSERT dp[i-1][j]->DELETE
                                                                                  //dp[i-1][j-1]->REPLACE
                }
            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        int minDistCost=minDistanceDP(word1,n,word2,m);
        return minDistCost;
    }
};
