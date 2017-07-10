/*
Given two strings str1 and str2, find the shortest string that has both str1 and str2 as subsequences
1) Find Longest Common Subsequence (lcs) of two given strings. For example, lcs of “geek” and “eke” is “ek”.

2) Insert non-lcs characters (in their original order in strings) to the lcs found above, and return the result. So “ek” becomes “geeke” which is shortest common 
supersequence.
Length of the shortest supersequence  = (Sum of lengths of given two strings) - 
                                        (Length of LCS of two given strings) 
*/



// Returns length of the shortest supersequence of X and Y
int superSeq(char* X, char* Y, int m, int n)
{
    int dp[m+1][n+1];
 
    // Fill table in bottom up manner
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
           // Below steps follow above recurrence
           if (!i)
               dp[i][j] = j;
           else if (!j)
               dp[i][j] = i;
           else if (X[i-1] == Y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
           else
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
        }
    }
 
    return dp[m][n];
}
