/*
Problem Statement-
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/



class Solution {
public:
    int uniquePathWithObstacleDP(vector<vector<int>> &a){
    int m=a.size();
    int n=a[0].size();
    int dp[m][n];
    //base case setting
    if(a[0][0]==0)
        dp[0][0]=1;
    else
        dp[0][0]=0;
    //initializing first row and coloumn
    for(int i=1;i<n;i++){
        if(a[0][i]==1)
            dp[0][i]=0;
        else
            dp[0][i]=dp[0][i-1];
    }
    for(int i=1;i<m;i++){
        if(a[i][0]==1)
            dp[i][0]=0;
        else
            dp[i][0]=dp[i-1][0];
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
           if(a[i][j]==1)
                dp[i][j]=0;
            else
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return uniquePathWithObstacleDP(obstacleGrid);
    }
};
