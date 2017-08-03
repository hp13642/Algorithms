/*
Problem Statement-
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented 
into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

class Solution {
public:
    bool dictContains(string str,vector<string> &dict){
        for(int i=0;i<dict.size();i++){
            if(dict[i].compare(str)==0)
                return true;
        }
        return false;
    }
    bool wordBreakDP(string &s,vector<string> &dict){
        int size=s.length();
        bool dp[size+1];
        memset(dp,false,sizeof(dp));
        for(int i=1;i<=size;i++){
            if(!dp[i] && dictContains(s.substr(0,i),dict))
                dp[i]=true;
            if(dp[i]){
                if(i==size)
                    return true;
                for(int j=i+1;j<=size;j++){
                    if(!dp[j] && dictContains(s.substr(i,j-i),dict))
                        dp[j]=true;
                    if(j==size && dp[j])
                        return true;
                }
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.length()==0)
            return true;
        return wordBreakDP(s,wordDict);
    }
};
