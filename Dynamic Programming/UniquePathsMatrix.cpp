/*
Problem Statement-
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the 
grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/


class Solution {
public:
    int uniquePathsDP(int m,int n){
        int dp[m][n];       
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0)
                    dp[i][j]=1;
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
    int uniquePaths(int m, int n) {
        if(m==1 || n==1)
            return 1;
        else
            return uniquePathsDP(m,n);
    }
};
