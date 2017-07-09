/*
Problem Statement-
A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the 
remaining elements. Longest common subsequence (LCS) of 2 sequences is a subsequence, with maximal length, which is common to both the 
sequences. 
Given two sequence of integers,  and , find any one longest common subsequence.

In case multiple solutions exist, print any of them. It is guaranteed that at least one non-empty common subsequence will exist.
*/


#include<bits/stdc++.h>
using namespace std;

vector<int> longestSubsequenceDP(vector<int> &a,int n,vector<int> &b,int m){
    int dp[n+1][m+1];
    int size;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0)
                dp[i][j]=0;
            else{
                if(a[i-1]==b[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    size=dp[n][m];
    //cout<<size<<endl;
    vector<int> result(size);
    int i=n,j=m,k=size;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            result[--k]=a[i-1];
            i--;
            j--;
        }
        else if(dp[i][j]==dp[i-1][j])
            i--;
        else
            j--;
    }
    return result;
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int j=0;j<m;j++)
        cin>>b[j];
    vector<int> longestSubseq=longestSubsequenceDP(a,n,b,m);
    int size=longestSubseq.size();
    for(int i=0;i<size;i++){
        if(i<size-1)
            cout<<longestSubseq[i]<<" ";
        else
            cout<<longestSubseq[i]<<endl;
    }
    return 0;
}
