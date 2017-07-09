/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/

//Method-1 using Dynamic Programming in O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0 || n==1)
            return n;
        vector<int> LIS(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && LIS[i]<LIS[j]+1)
                    LIS[i]=LIS[j]+1;
            }
        }
        int max=*(max_element(LIS.begin(),LIS.end()));
        return max;
    }
};

//Method-2 using array and binary serach concept in O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0 || n==1)
            return n;
        vector<int> LIS;
        vector<int>::iterator it;
        for(int i=0;i<n;i++){
            it=lower_bound(LIS.begin(),LIS.end(),nums[i]);
            if(it==LIS.end())
                LIS.push_back(nums[i]);
            else
                *it=nums[i];
        }
        return LIS.size();
    }
};
