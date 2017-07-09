/*
Problem Statement-
Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is 
minimum.

If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the 
value of abs(sum(Subset1) – sum(Subset2)) should be minimum.

Example:

Input:  arr[] = {1, 6, 11, 5} 
Output: 1
Explanation:
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11		
*/




#include<bits/stdc++.h>
using namespace std;
int canPartitionDP(vector<int> &nums,int n){
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=nums[i];
        //cout<<sum<<endl;
        //if sum is odd two partition with equal sum is not possible
        // if(sum%2)
        //     return false;
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
        // return dp[tarSum][n];
        for(int i=tarSum;i>0;i--){
            if(dp[i][n]){
                int maxAbsDiff=abs(sum-2*i);
                return maxAbsDiff;
            }
        }
    }
    int canPartition(vector<int>& nums) {
        int n=nums.size();
        return canPartitionDP(nums,n);
    }
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> a(n);
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    int absDifference=canPartition(a);
	    cout<<absDifference<<endl;
	}
	return 0;
}
