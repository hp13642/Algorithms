/*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of 
elements in both subsets is equal.

Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.
Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
*/

class Solution {
public:
    bool canPartitionDP(vector<int> &nums,int n){
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=nums[i];
        //cout<<sum<<endl;
        //if sum is odd two partition with equal sum is not possible
        if(sum%2)
            return false;
        //Deviding sum into two part so that problem became similier to Subset sum
        //if sum of sum element of set is equal to sum/2 then set can be partitioned into two subset such that their sum is equal
        int tarSum=sum/2;
        bool dp[tarSum+1][n+1];
        for(int i=0;i<=n;i++)
            dp[0][i]=true;
        for(int j=1;j<=tarSum;j++)
            dp[j][0]=false;
        for(int i=1;i<=tarSum;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=dp[i][j-1];
                    if(i>=nums[j-1])
                        dp[i][j]=dp[i][j] || dp[i-nums[j-1]][j-1];
            }
        }
        return dp[tarSum][n];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        return canPartitionDP(nums,n);
    }
};
